// Choc V2 Switch Hole Cover
// All measurements in millimeters

// Main Parameters
plate_thickness = 1.2;  // Thickness of the cover plate
tolerance = 0.2;    // Tolerance for better fit

// Choc V2 switch cutout dimensions
switch_width = 13.8;  // Width of the switch cutout
switch_length = 13.8;   // Length of the switch cutout

// Lip dimensions for securing the cover
lip_height = 1.0;     // Height of the securing lip
lip_thickness = 0.8;    // Thickness of the lip

module switch_cover() {
  difference() {
    union() {
      // Main cover plate
      translate([0, 0, lip_height])
        cube([switch_width + 2, switch_length + 2, plate_thickness], center=true);
      
      // Securing lip
      difference() {
        // Outer lip
        translate([0, 0, lip_height/2])
          cube([switch_width, switch_length, lip_height], center=true);
        
        // Inner cutout
        translate([0, 0, lip_height/2])
          cube([switch_width - lip_thickness*2, 
             switch_length - lip_thickness*2, 
             lip_height + 0.1], center=true);
      }
    }
    
    // Chamfer the top edges for better appearance
    // #translate([0, 0, plate_thickness + lip_height - 0.1])
    // rotate([0, 0, 45])
    // cube([switch_width * 1.5, 1, 1], center=true);
  }
}

// Generate the model
switch_cover();
