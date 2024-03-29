#!/usr/bin/env python
# -*- coding: utf-8 -*-

from enum import Enum, auto, unique

@unique
class ErrorCode(Enum):
	WTF = -1
	OK = 0
	NOT_IMPLEMENTED = 1
	INCORRECT_PARAMETERS = 2