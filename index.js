const myArray = new Array();
var numberList = 0; // Album Increment

    function showMessage(){ 
        document.getElementById("display_message").innerHTML = "";
        numberList = numberList+1;
        var artistField = document.getElementById("artistfield").value;
        var albumField = document.getElementById("albumfield").value;
        var ratingField = document.getElementById("ratingfield").value;
        console.log(artistField);
        console.log(albumField);
        console.log(ratingField);
        var returnString = numberList + ".  " + "Artist: " +  artistField.bold() + "   " + " Album: " + albumField.bold() + "   " + " Rating: " +ratingField.bold() +"<br />";
        myArray.push(returnString);
        printArray();
    }

    function deleteAlbum() {
        var numberField = document.getElementById("numberfield").value;
        delete myArray[numberField-1];
        document.getElementById("display_message").innerHTML = "";
        printArray();        

    }

    function printArray() {
        document.getElementById("display_message").innerHTML = "";
        for (i = 0; i < myArray.length; i++)
            document.getElementById("display_message").innerHTML += myArray[i];
    }