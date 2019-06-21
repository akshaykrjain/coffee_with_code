#!/bin/bash
echo "Analysing Web Server Access Log.."
echo "Log Path : $1";

awk '{print $1}' $1 | uniq -c | sort -r;
