/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> hci.o -> r_hci_evt_mask_check
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint r_hci_evt_mask_check(int param_1)

{
  uint uVar1;
  uint uVar2;
  byte bVar3;
  uint uVar4;
  
  if (*(short *)(param_1 + 4) == 0x1103) {
    uVar4 = (uint)*(byte *)(param_1 + 8);
    if (0x3f < uVar4) {
      if (0x58 < uVar4) {
        return 0;
      }
      uVar4 = uVar4 - 0x40 & 0xff;
      bVar3 = (&r_modules_funcs_p)[uVar4 >> 3];
      goto _L17;
    }
  }
  else {
    if (*(short *)(param_1 + 4) != 0x1104) {
      return 0;
    }
    uVar4 = 0x3e;
  }
  uVar2 = (int)(uint)(byte)(&hci_env)[(uVar4 - 1 & 0xff) >> 3] >> (uVar4 - 1 & 7) & 1;
  uVar1 = uVar2 ^ 1;
  if (uVar2 == 0) {
    return uVar1;
  }
  if (uVar4 != 0x3e) {
    return uVar1;
  }
  if (0xef < *(byte *)(param_1 + 0xc)) {
    return 0;
  }
  bVar3 = *(byte *)(param_1 + 0xc) - 1;
  uVar4 = (uint)bVar3;
  bVar3 = (&r_hli_funcs_p)[bVar3 >> 3];
_L17:
  return ~((int)(uint)bVar3 >> (uVar4 & 7)) & 1;
}

