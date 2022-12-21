// The Pork Chop
//
// A Mechanical Keyboard

$fn = 128;

height = 4.6;
feet_height = 8;
wall = 5;
pcb_height = 1.2;
mountin_hole = 3;
membrane = 2;

key_distance = 19;

key_hole = 14;
key_tab_indent = 0.5;
key_tab_width = 5.0;
key_tab_submersion = 1.3;

module mirror2(vector) {
  children();
  mirror(vector) children();
}

module keyholder () {
  margin = 0.5;
  h = height+(2*margin);
  translate([0,0,-0.5]) {
    union() {
      // hole
      linear_extrude(h) {
        square(key_hole, center=true);
      }
      // botton indent
      linear_extrude(h-margin-key_tab_submersion) {
        mirror2([0,1,0]) {
          translate([0,-(key_hole+key_tab_indent)/2,0]) {
            square([key_tab_width,key_tab_indent], center=true);
          }
        }
      }
    }
  }
}

module key (units) {
  union() {
    translate([0,0,height-1]) {
      linear_extrude(2) {
        square([key_distance*units-1,key_distance-1],  center=true);
      }
    }
    keyholder();
  }
}

module array (count, distance) {
  for (i=[0:1:count-1]) {
    translate([0,distance*i,0])
      children();
  }
}

module two_keys () {
  array(2, key_distance)
    key(1);
}

module three_keys () {
  array(3, key_distance)
    key(1);
}

module five_keys () {
  three_keys();
  translate([key_distance,key_distance/2,0]) two_keys();
}

module turn (degree) {
  rotate([0,0,degree])
    children();
}

 module index_finger_full () {
  turn(25) mirror([1,0,0]) five_keys();
}

module middle_finger () {
  turn(23) three_keys();
}

module ring_finger () {
  turn(20) three_keys();
}

module pinkie_full () {
  turn(15) five_keys();
}

module thumbs () {
  translate([86,77]) turn(9) key(1);
  translate([59,69]) turn(25) key(1);
  translate([38,60]) turn(-45) key(1.5);
  translate([25,45]) turn(-38) key(1.25);
  translate([14,28]) turn(-29) key(1);
}

module right_hand () {
  translate([49,90,0]) index_finger_full();
  translate([63.5,104,0]) middle_finger();
  translate([84,104,0]) ring_finger();
  translate([107,94,0]) pinkie_full();
  thumbs();
}

module plate_2d () {
  minkowski() {
    difference() {
      union() {
        //translate([5,5,0]) square([110,98]);
        //translate([72.9,100]) circle(68);
        translate([10,5,0]) square([100,90]);
        translate([74,101]) circle(64);
      }
      translate([106,-18,0]) circle(80);
      //translate([145,50,0]) circle(40);
      //translate([145,-34,0]) turn(40) square(100);
    }
    circle(5);
  }
}

module interior_2d () {
  offset(-wall) plate_2d();
}

module interior_3d () {
  translate([0,0,-0.5]) {
    linear_extrude(feet_height+0.5) {
      interior_2d();
    }
  }
}

module flat_cable_3d () {
  translate([65,160,-1]) {
    linear_extrude(6) {
      turn(0) square([15,15]);
    }
  }
}

module plate_3d () {
  difference() {
    linear_extrude(height+feet_height) {
      plate_2d();
    }
    interior_3d();
    flat_cable_3d();
  }
}

module right_side () {
  difference() {
    plate_3d();
    translate([3,-3,feet_height]) right_hand();
  }
}

*right_side();

module left_side () {
  mirror([1,0,0]) right_side();
}

*left_side();

module complete_2d () {
  mirror2([1,0,0]) plate_2d();
  difference () {
    translate([0,80,0]) square([35,150], center=true);
    translate([0,150,0]) square([50,20], center=true);
  }
  translate([-10,0,0]) square(20);
}

module standoff () {
  linear_extrude(pcb_height) circle(mountin_hole / 2);
  translate([0,0,pcb_height]) {
    linear_extrude(membrane) circle(mountin_hole / 2 + 1);
  }
}

*standoff();

module standoffs () {
  mirror2([1,0,0]) {
    translate([22,12,0]) standoff();
    translate([96,89,0]) standoff();
    translate([113,135,0]) standoff();
    translate([36,137,0]) standoff();
    translate([38,74,0]) standoff();
  }
}

module complete_interior_3d () {
  translate([0,0,-0.5]) {
    difference() {
      linear_extrude(feet_height+0.5) {
        offset(-5) complete_2d();
      }
      translate([0,0,feet_height-0.5]) standoffs();
    }
  }
}

module complete_plate_3d () {
  difference() {
    linear_extrude(height+feet_height) {
      complete_2d();
    }
    complete_interior_3d();
  }
}

module keyboard () {
  difference () {
    complete_plate_3d();
    mirror2([1,0,0]) {
      translate([3,-3,feet_height]) right_hand();
    }
  }
}

keyboard();

// top plate
*projection() keyboard();

module pcb () {
  linear_extrude(pcb_height) {
    difference() {
      offset(-wall-1) complete_2d();
      projection(cut=true) standoffs();
    }
  }
}

*translate([0,0,feet_height - pcb_height]) pcb();

// pcb key guide
*projection() difference() {
  pcb();
  mirror2([1,0,0]) {
    translate([3,-3,-key_tab_submersion/2]) right_hand();
  }
}

*projection() {
  linear_extrude(pcb_height) {
    offset(-wall-1) complete_2d();
  }
}
