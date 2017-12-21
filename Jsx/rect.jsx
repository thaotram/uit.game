function isSelected(selection) {
    try {
        selection.bounds;
        return true;
    } catch (e) {
        return false
    }
}

function copyTextToClipboard(string) {
    const keyTextData = app.charIDToTypeID('TxtD');
    const ktextToClipboardStr = app.stringIDToTypeID("textToClipboard");

    var textStrDesc = new ActionDescriptor();

    textStrDesc.putString(keyTextData, string);
    executeAction(ktextToClipboardStr, textStrDesc, DialogModes.NO);
}

function boundsToString(b) {
    return '[' + b.join(",").replace(/( px|\s)/g, '') + ']';
}

function fromLayers(layers) {
    var length = layers.length;
    var array = [];
    for (var i = 0; i < length; i++) {
        if (layers[i].name != "_") {
            if (layers[i].name != "")
                array.push(layers[i].typename == "LayerSet" ?
                    fromLayers(layers[i].layers) :
                    boundsToString(layers[i].bounds)
                );
        }
    }
    return array.join(",");
}

function fromeSet(setName) {
    var string = fromLayers(
        app.activeDocument.layerSets.getByName(setName).layers
    );
    return '"' + setName + '":[' + string + ']';
}

if (app.documents.length != 0) {
    var type = [
        "NPC_Peddler",
        "NPC_Camel",
        "NPC_Stall",
        
        "Enemy_Assassin",
        "Enemy_Circus",
        "Enemy_Fat",
        "Enemy_Pirates",
        "Enemy_Straw",
        "Enemy_Thin",

        "Static_Abubonus",
        "Static_Apple",
        "Static_Black_Magic_Lamp",
        "Static_Extra_Health",
        "Static_Genie_Bonus",
        "Static_Restart_Point",
        "Static_Spend_These",
       
        "Static_Block_Drop",
        "Static_Stick",

        "Bar",
        "Rope",
        "Stairs_backslash",
        "Stairs_slash",
        "Square",
        "Horizontal",

        "_Stairs_slash",
        "_Stairs_backslash",
        "_Square"
    ];
    var arr = [];
    for (var i = 0; i < type.length; i++) {
        arr.push(fromeSet(type[i]));
    }
    var string = '{"name": "AgrabahMarket_Block","block": {' + arr.join(",") + '}}'
    copyTextToClipboard(string);
    alert(string);
}