// Thrice V1
//
// A Split Mechanical Keyboard

// Level of detail
$fn = 128;

module mirror2(vector) {
  children();
  mirror(vector) children();
}

module array (count, distance) {
  for (i=[0:1:count-1]) {
    translate([0,distance*i,0])
      children();
  }
}

module turn (degree) {
  rotate([0,0,degree])
    children();
}

// All constants are in mm
key_side = 15;
plate_thickness = 3;
feet_thickness = 0.9;

module key_holder () {
    lip_thickness = 0.8;
    lip_overhang = 0.5;
    trench_thickness = 1.2;
    lip_total = 2*lip_overhang;
    union() {
      // hole
      linear_extrude(plate_thickness) {
        square(key_side - lip_total, center=true);
      }
      translate([0,0,plate_thickness - lip_thickness]) {
        linear_extrude(lip_thickness) {
          square(key_side, center=true);
        }
      }
      linear_extrude(trench_thickness) {
        square(key_side, center=true);
      }
    }
}

key_holder();

//
// OLD
//

height = 4.6;
feet_height = 8;
wall = 4;
pcb_height = 1.2;
mountin_hole = 3;
membrane = 1;
key_distance = 19;
key_hole = 14;
key_tab_indent = 0.5;
key_tab_width = 5.0;
key_tab_submersion = 1.3;

module keyholder () {
  margin = 0.5;
  h = height+(2*margin);
  translate([0,0,-0.5]) {
    union() {
      // hole
      linear_extrude(h) {
        square(key_hole, center=true);
      }
      // botton indent for lock
      #linear_extrude(h-margin-key_tab_submersion) {
        mirror2([0,1,0]) {
          translate([0,-(key_hole+key_tab_indent)/2,0]) {
            square([key_tab_width,key_tab_indent], center=true);
          }
        }
      }
    }
  }
}

// OLD for comparison
translate([20,20,0]) {
  keyholder();
}

module key (units) {
  union() {
    keyholder();
    // Outline of keycap, hidden by default
    *translate([0,0,height-1]) {
      linear_extrude(2) {
        square([key_distance*units-1,key_distance-1], center=true);
      }
    }
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

module four_keys () {
  three_keys();
  translate([key_distance,key_distance,0]) turn(90) key(1.5);
}

module five_keys () {
  three_keys();
  translate([key_distance,key_distance/2,0]) two_keys();
}

module index_finger_full () {
  turn(15) mirror([1,0,0]) five_keys();
}

module middle_finger () {
  turn(15) three_keys();
}

module ring_finger () {
  turn(15) three_keys();
}

module pinky_full () {
  turn(15) four_keys();
}

module thumbs () {
  translate([71.7,80]) turn(-75) key(1.5);
  translate([50,68]) turn(15) key(1);
  translate([31.5,63]) turn(-75) key(1.5);
  translate([13,58]) turn(-75) key(1);
}

module right_hand () {
  translate([49,89,0]) index_finger_full();
  translate([65.5,103,0]) middle_finger();
  translate([86.5,99,0]) ring_finger();
  translate([108,93,0]) pinky_full();
  thumbs();
}

module plate_2d () {
  minkowski() {
    difference() {
      union() {
        translate([8,46,0]) square([100,82]);
        translate([82,104]) circle(50);
      }
      translate([98,-33,0]) circle(100);
    }
    circle(7);
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

module plate_3d () {
  difference() {
    linear_extrude(height+feet_height) {
      plate_2d();
    }
    interior_3d();
  }
}

module right_side () {
  difference() {
    plate_3d();
    translate([3,-3,feet_height]) right_hand();
  }
}

module left_side () {
  mirror([1,0,0]) right_side();
}

// Complete 2D area without holes
module complete_2d () {
  difference () {
    union () {
      mirror2([1,0,0]) plate_2d();
      translate([0,87,0]) square([35,96], center=true);
    }
    *translate([0,133,0]) square([38,10], center=true);
    *translate([-18,150,0]) circle(22);
    *translate([18,150,0]) circle(22);
  }
}

*complete_2d();

module standoff () {
  difference() {
    translate([0,0,pcb_height]) {
      linear_extrude(membrane) circle(mountin_hole / 2 + 1);
    }
    translate([0,0,-1]) {
      linear_extrude(pcb_height + membrane + 2) 
        circle(mountin_hole / 2 - 0.1);
    }
  }
}

module standoffs_placement () {
  mirror2([1,0,0]) {
    translate([36,49,0]) children();
    translate([93,84,0]) children();
    translate([115,125,0]) children();
    translate([70,143,0]) children();
    translate([24,122,0]) children();
  }
}

module standoffs () {
  standoffs_placement() {
    standoff();
  }
}

module complete_interior_3d () {
  translate([0,0,-0.5]) {
    difference() {
      linear_extrude(feet_height+0.5+membrane) {
        offset(-wall) complete_2d();
      }
      translate([0,0,feet_height-0.5]) standoffs();
    }
  }
}

module complete_keyboard_3d () {
  difference() {
    linear_extrude(height+feet_height) {
      complete_2d();
    }
    complete_interior_3d();
  }
}

module keyboard () {
  difference () {
    complete_keyboard_3d();
    mirror2([1,0,0]) {
      translate([3,-3,feet_height]) right_hand();
    }
  }
}

*keyboard();

module holes () {
  standoffs_placement() {
    translate([0,0,-1]) {
      linear_extrude(height + membrane - 1) 
        circle(mountin_hole / 2 - 0.1);
    }    
  }
}

module plate () {
  difference() {
    union() {
      translate([0,0,membrane])
      difference() {
        linear_extrude(height-membrane) {
          complete_2d();
        }
        // cut out for flat cable
        translate([0,0,-1]) {
          linear_extrude(height-membrane + 2) {
            translate([0,65,0]) square([12,8], center=true);
          }
        }
        // cut out for USB plug
        translate([0,0,-2]) {
          linear_extrude(height-membrane) {
            translate([0,135,0]) square([15,10], center=true);
          }
        }
      }  
      translate([0,0,-membrane]) standoffs();
    }
    holes();
    mirror2([1,0,0]) {
      translate([3,-3,0]) right_hand();
    }
  }
}

// top plate for 3D printing
*plate();

// trackpad
*translate([0,85,0]) circle(20);


module pcb () {
  linear_extrude(pcb_height) {
    difference() {
      offset(-wall-1) complete_2d();
      projection(cut=true) holes();
    }
  }
}

// guide for placing the switches & holes on the pcb
*projection() difference() {
  pcb();
  mirror2([1,0,0]) {
    translate([3,-3,-key_tab_submersion/2]) right_hand();
  }
}

// pcb outline
*projection() {
  linear_extrude(pcb_height) {
    offset(-wall-1) complete_2d();
  }
}
