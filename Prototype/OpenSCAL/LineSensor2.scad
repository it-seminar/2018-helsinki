$fn = 90;

function size(v) = sqrt(v.x*v.x + v.y*v.y + v.z*v.z);

fs1 = [-0.35, 0.45, -0.1];
fs2 = [0.35, 0.45, -0.1];

led = [0, 1.25, -0.1];
//led2 = [0.35, 1.25, -0.2];

ch = 1.6;

function size(v) = sqrt(v.x*v.x

//difference() {
%    translate([-0.8, 0, 0]) cube([1.6, 1.6, ch]);
    
    translate(fs1) cylinder(h = 1.8, r = 0.25);
    translate(fs2) cylinder(h = 1.8, r = 0.25);
    
    translate(led) {
        cylinder(h = ch - 0.8, r = 0.25);
        cylinder(h = 0.25, r = 0.32);
        }
     
    
         
 //   }

