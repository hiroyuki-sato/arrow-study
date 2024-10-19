#!/usr/bin/env python

import pyarrow as pa
import random

NROWS = 8192
NCOLS = 16

data = [pa.array([random.uniform(-2,2) for x in range(NROWS)]) for _ in range(NCOLS)]

cols = ['c' + str(i) for i in range(NCOLS)]

rb = pa.RecordBatch.from_arrays(data,cols)
print(rb.schema)
print(rb.num_rows)
