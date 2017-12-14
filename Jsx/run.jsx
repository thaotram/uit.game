function isSelected(selection) {
    try {
        selection.bounds;
        return true;
    } catch (e) {
        return false
    }
}

function copyTextToClipboard(txt) {
    const keyTextData = app.charIDToTypeID('TxtD');
    const ktextToClipboardStr = app.stringIDToTypeID("textToClipboard");

    var textStrDesc = new ActionDescriptor();

    textStrDesc.putString(keyTextData, txt);
    executeAction(ktextToClipboardStr, textStrDesc, DialogModes.NO);
}

if (app.documents.length != 0) {
    var selection = app.activeDocument.selection;

    if (isSelected(selection)) {
        var width = (selection.bounds[2] - selection.bounds[0]),
            height = (selection.bounds[3] - selection.bounds[1]),
            left = selection.bounds[0],
            top = selection.bounds[1];
        string = '[' + left + ',' + top + ',' + width + ',' + height + ',0,0]';
        string = string.replace(/ px/g, '').replace(/\s/g, '');
        copyTextToClipboard(string);
        alert(string);
    }
}