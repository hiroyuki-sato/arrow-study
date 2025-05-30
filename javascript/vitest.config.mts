import { defineConfig } from 'vitest/config';
//const vite = require('vite');

export default defineConfig({
  test: {
    globals: true,
    environment: 'node',
    coverage: {
      provider: 'c8',
    },
  },
});
