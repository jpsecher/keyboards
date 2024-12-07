// Choc V2 Switch Hole Cover
// All measurements in millimeters
$fn = 128;

// Main Parameters
plate_thickness = 1.2;  // Thickness of the cover plate
plate_overhang = 2;
// tolerance = 0.2;    // Tolerance for better fit

switch_width = 13.8;  // Width of the switch cutout
lip_height = 0.4;
lip_width = 1;
lip_length = 10;

plate_width = switch_width + plate_overhang;

module lid_raw() {
    minkowski() {
        cube([switch_width, switch_width, plate_thickness]);
        cylinder(r=0.8,center=true);
    }
}
*lid_raw();

module lid() {
    translate([-switch_width / 2, -switch_width / 2, 0])
        lid_raw();
}

module rim_raw() {
    difference() {
        minkowski() {
            cube([switch_width - 1, switch_width - 1, 2]);
            cylinder(r=0.5,center=true);
        }
        translate([2*lip_width/2-0.5, 2*lip_width/2-0.5, 0])
            cube([switch_width - 2*lip_width, switch_width - 2*lip_width, 3]);
    }
}
*rim_raw();

module rim() {
    translate([-switch_width / 2 + 0.5, -switch_width / 2 + 0.5, 1])
        rim_raw();
}

module tap_raw() {
    union() {
        translate([0, 0, 1.65+0.5])
            minkowski() {
                cube([lip_width, lip_width, lip_height]);
                sphere(r=0.4);
            }
        translate([0, lip_length - lip_width, 1.65+0.5])
            minkowski() {
                cube([lip_width, lip_width, lip_height]);
                sphere(r=0.4);
            }
    }
}

module tap() {
    translate([-lip_width / 2, -lip_width / 2, plate_thickness])
        tap_raw();
}

module taps() {
    translate([(switch_width - lip_width)/2,-((lip_length-lip_width)/2),0])
        tap();
}

module switch_cover() {
    difference() {
        union() {
            lid();
            rim();
            taps();
            rotate([180,180,0]) taps();
        }
    }
}

switch_cover();
