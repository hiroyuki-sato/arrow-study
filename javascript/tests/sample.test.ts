//import { tableFromArrays, vectorFromArray } from 'apache-arrow';
//import { describe, it, expect } from 'vitest';
//
//const vite = require('vite');
const arrow = require('apache-arrow');
//import vite from 'vite';

describe('Apache Arrow 基本テスト', () => {
  it('Arrowのテーブル作成', () => {
    // データをベクトルに変換
    const column1 = arrow.vectorFromArray([1, 2, 3]); // 数値データ
    const column2 = arrow.vectorFromArray(['a', 'b', 'c']); // 文字列データ

    // テーブルを作成
    const table = arrow.tableFromArrays({
      col1: column1,
      col2: column2,
    });

    // テーブルの内容を検証
    expect(table.numCols).toBe(2); // カラム数が2であること
    expect(table.numRows).toBe(3); // 行数が3であること
    //expect(table.getColumn('col1')?.toArray()).toEqual([1, 2, 3]); // col1の値を検証
    //expect(table.getColumn('col2')?.toArray()).toEqual(['a', 'b', 'c']); // col2の値を検証
  });

/*
  it('Arrowのベクトル操作', () => {
    // ベクトルの作成と操作
    const vector = vectorFromArray([10, 20, 30]);
    const result = vector.toArray().map((x) => x * 2);

    // 値の検証
    expect(result).toEqual([20, 40, 60]);
  });
*/
});

