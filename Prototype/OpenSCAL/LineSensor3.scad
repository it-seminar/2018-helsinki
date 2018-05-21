$fn = 90;

module lineSensor() {
    function size(v) = sqrt(v.x*v.x + v.y*v.y + v.z*v.z);

    fs1 = [-4.5, 4.5, -1];
    fs2 = [4.5, 4.5, -1];

    led1 = [-4.5, 12.5, -2];
    led2 = [4.5, 12.5, -2];

    ch = 10;

    difference() {
        translate([-10, 0, 0]) cube([20, 17, ch]);
        
        translate(fs1) {
            cylinder(h = 18, d = 5.5);
            }
        translate(fs2) cylinder(h = 18, d = 5.5);
        
        translate(led1) {
            cylinder(h = ch + 10, d = 6.0);
            cylinder(h = 3.5, d = 7.0);
            }
        translate(led2) {
            cylinder(h = ch + 10, d = 6.0);
            cylinder(h = 3.5, d = 7.0);
            }
        
        }
    }

lineSensor();