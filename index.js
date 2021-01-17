    function showMessage(){ 
        var artistField = document.getElementById("artistfield").value;
        var albumField = document.getElementById("albumfield").value;
        var ratingField = document.getElementById("ratingfield").value;
        console.log(artistField);
        console.log(albumField);
        console.log(ratingField);
        var returnString = "Artist: " +  artistField + "   " + " Album: " + albumField + "   " + " Rating: " +ratingField;
        return document.getElementById("display_message").innerHTML = returnString;
    }
