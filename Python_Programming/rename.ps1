foreach($file in Get-ChildItem $PWD)
{
    if ($file.name.EndsWith(".py"))
    {
        $newName = "Assignment"+ $args[0] + "_" + $file.name
        mv $file.name $newName
    }
}