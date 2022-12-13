// The Pork Chop
//
// A Mechanical Keyboard

$fn = 128;

height = 4.6;
feet_height = 8;

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
      // top indent
      *translate([0,0,margin+key_tab_submersion]) {
        linear_extrude(h-margin-key_tab_submersion) {
          mirror2([1,0,0]) {
            translate([-(key_hole+key_tab_indent)/2,0,0]) {
              square([key_tab_indent,key_tab_width], center=true);
            }
          }
        }
      }
    }
  }
}

module key (units) {
  union() {
    *translate([0,0,height-1]) {
      linear_extrude(2) {
        square([key_distance-1,key_distance*units-1], center=true);
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
  translate([85,82]) turn(20) key(1);
  translate([59,69]) turn(25) key(1);
  translate([38,60]) turn(45) key(1.5);
  translate([25,42]) turn(61) key(1.5);
  translate([17,21]) turn(77) key(1.5);
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
        translate([5,5,0]) square([130,105]);
        translate([77,107]) circle(72);
      }
      translate([126,-10,0]) circle(88);
    }
    circle(5);
  }
}

module interior_2d () {
  offset(-5) plate_2d();
}

module interior_3d () {
  translate([0,0,-0.5]) {
    linear_extrude(feet_height+0.5) {
      interior_2d();
    }
  }
}

module flat_cable_3d () {
  translate([65,170,-1]) {
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
    translate([5,7,feet_height]) right_hand();
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
    translate([0,125,0]) square([35,40], center=true);
    translate([0,155,0]) square([50,20], center=true);
  }
  translate([-5,0,0]) square(10);
}

module complete_interior_3d () {
  translate([0,0,-0.5]) {
    linear_extrude(feet_height+0.5) {
      offset(-5) complete_2d();
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
    mirror2([1,0,0]) translate([4,8,feet_height]) right_hand();
  }
}

*keyboard();

projection() keyboard();
