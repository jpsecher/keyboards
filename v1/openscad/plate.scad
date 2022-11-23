// The Tree
//
// A Mechanical Keyboard

$fn = 128;

height = 4;

key_distance = 19;

key_hole = 13.9;
key_tab_indent = 0.5;
key_tab_width = 5.0;
key_tab_submersion = 1.3;

module mirror2(vector) {
  children();
  mirror(vector) children();
}

module keyholder () {
  h = height+1;
  translate([0,0,-0.5]) {
    union() {
      linear_extrude(h) {
        square(key_hole, center=true);
      }
      linear_extrude(h-0.5-key_tab_submersion) {
        mirror2([0,1,0]) {
          translate([0,-(key_hole+key_tab_indent)/2,0]) {
            square([key_tab_width,key_tab_indent], center=true);
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
  translate([55,70]) turn(40) keyholder();
  translate([41,57]) turn(55) keyholder();
  translate([32,39]) turn(70) keyholder();
  translate([27,19]) turn(85) keyholder();
}

module right_hand () {
  translate([33,79,0]) index_finger();
  translate([48,90,0]) index_finger();
  // three only: translate([63,103,0]) middle_finger();
  translate([71,82,0]) middle_finger();
  translate([82,104,0]) ring_finger();
  translate([104,94,0]) pinkie();
  translate([118,109,0]) pinkie_extra();
  thumbs();
}

module plate () {
  linear_extrude(height) {
    minkowski() {
      difference() {
        union() {
          translate([5,5,0]) square([120,105]);
          translate([68.88,105]) circle(64);
        }
        translate([140,-13,0]) circle(90);
      }
      circle(5);
    }
  }
}

difference() {
  plate();
  right_hand();
}
