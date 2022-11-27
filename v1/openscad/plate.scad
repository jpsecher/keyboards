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

module four_keys () {
  keyholder();
  // Make room for a 1.5u key (ie, 1.25u extra space)
  translate([0,(key_distance*1.25),0])
    three_keys();
}

module turn (degree) {
  rotate([0,0,degree])
    children();
}

module index_finger () {
  turn(25) three_keys();
}

module middle_finger () {
  turn(23) four_keys();
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
  translate([54,69]) turn(40) keyholder();
  translate([38,56]) turn(55) keyholder();
  translate([29,38]) turn(70) keyholder();
  translate([24,18]) turn(85) keyholder();
}

module right_hand () {
  translate([33,79,0]) index_finger();
  translate([49,90,0]) index_finger();
  // three only: translate([63,103,0]) middle_finger();
  translate([73,82,0]) middle_finger();
  translate([84,104,0]) ring_finger();
  translate([106,94,0]) pinkie();
  translate([121,109,0]) pinkie_extra();
  thumbs();
}

module plate_2d () {
  minkowski() {
    difference() {
      union() {
        translate([5,5,0]) square([120,105]);
        translate([68.88,105]) circle(64);
      }
      translate([130,-13,0]) circle(93);
    }
    circle(5);
  }
}

module rim_2d () {
  difference() {
    plate_2d();
    offset(-5) plate_2d();
  }
}

module rim_3d () {
  translate([0,0,-feet_height]) {
    linear_extrude(feet_height) {
      rim_2d();
    }
  }
}

module plate_3d () {
  linear_extrude(height) {
    plate_2d();
  }
}

module right_side () {
  difference() {
    union() {
      plate_3d();
      rim_3d();
    }
    right_hand();
  }
}

*plate_3d();
*rim_3d();
right_side();

module left_side () {
  mirror([1,0,0]) right_side();
}

*union() {
  left_side();
  linear_extrude(height) {
    difference () {
      translate([0,115,0]) square([15,40], center=true);
      translate([0,137,0]) circle(7);
    }
    translate([-5,0,0]) square(10);
  }
  right_side();
}

module key_plate () {
  linear_extrude(height) {
    square([19,19], center=true);
  }
}

*difference() {
  key_plate();
  keyholder();
}
