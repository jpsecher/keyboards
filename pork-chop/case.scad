// The Pork Chop
//
// A Mechanical Keyboard

$fn = 128;

height = 5;
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

module array (count, distance) {
  for (i=[0:1:count-1]) {
    translate([0,distance*i,0])
      children();
  }
}

module two_keys () {
  array(2, key_distance)
    keyholder();
}

module three_keys () {
  array(3, key_distance)
    keyholder();
}

module turn (degree) {
  rotate([0,0,degree])
    children();
}

module index_finger () {
  turn(25) three_keys();
}

module index_finger_extra () {
  turn(25) two_keys();
}

module middle_finger () {
  turn(23) three_keys();
}

module ring_finger () {
  turn(20) three_keys();
}

module pinkie () {
  turn(15) three_keys();
}

module pinkie_extra () {
  turn(15) two_keys();
}

module thumbs () {
  translate([78,80]) turn(23) keyholder();
  translate([59,69]) turn(38) keyholder();
  translate([41,55]) turn(55) keyholder();
  translate([30,33]) turn(70) keyholder();
  translate([26,8]) turn(85) keyholder();
}

module right_hand () {
  translate([28,89,0]) index_finger_extra();
  translate([49,90,0]) index_finger();
  translate([63.5,104,0]) middle_finger();
  translate([84,104,0]) ring_finger();
  translate([107,94,0]) pinkie();
  translate([123,109,0]) pinkie_extra();
  thumbs();
}

module plate_2d () {
  minkowski() {
    difference() {
      union() {
        translate([5,5,0]) square([120,105]);
        translate([72,107]) circle(67);
      }
      translate([140,0,0]) circle(90);
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
  translate([35,160,-1]) {
    linear_extrude(4) {
      turn(30) square([15,15]);
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
    translate([0,7,feet_height]) right_hand();
  }
}

*right_side();

module left_side () {
  mirror([1,0,0]) right_side();
}

left_side();

module complete_2d () {
  mirror2([1,0,0]) plate_2d();
    difference () {
      translate([0,115,0]) square([15,40], center=true);
      translate([0,137,0]) circle(7);
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

*difference () {
  complete_plate_3d();
  mirror2([1,0,0]) translate([-1,8,feet_height]) right_hand();
}


