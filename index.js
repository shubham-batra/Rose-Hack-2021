const myArray = new Array();

    function showMessage(){ 
        document.getElementById("display_message").innerHTML = "";
        var artistField = document.getElementById("artistfield").value;
        var albumField = document.getElementById("albumfield").value;
        var ratingField = document.getElementById("ratingfield").value;
        console.log(artistField);
        console.log(albumField);
        console.log(ratingField);
        var returnString = "Artist: " +  artistField + "   " + " Album: " + albumField + "   " + " Rating: " +ratingField +"<br />";
        myArray.push(returnString);
        for (i = 0; i < myArray.length; i++)
            document.getElementById("display_message").innerHTML += myArray[i];
    }