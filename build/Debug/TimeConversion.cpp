string timeConversion(string s) {
    string zone = s.substr(s.length()-2); // get last two characters (AM/PM)
    string hour = s.substr(0,2); // get first two characters (hour)
     string rest = s.substr(2, 6);      // get rest of the string (minute, second)
    int h = stoi(hour);
    if(zone == "PM") {
      if (h != 12) h += 12; // 12 PM is 12 in 24 hour format
    }else{
       if (h == 12) h = 0; // 12 AM is 00 in 24 hour format
    }
     return (h < 10 ? "0" : "") + to_string(h) + rest;  // if hour is less than 10 then add 0 in front of it
  }
//   Input (stdin)
// 07:05:45PM
// Expected Output
// 19:05:45