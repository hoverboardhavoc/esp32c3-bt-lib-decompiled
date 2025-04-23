/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> hci.o -> r_hci_evt_mask_check
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint r_hci_evt_mask_check(int param_1)

{
  byte bVar1;
  uint uVar2;
  
  if (*(short *)(param_1 + 4) == 0x1103) {
    uVar2 = (uint)*(byte *)(param_1 + 8);
    if (0x3f < uVar2) {
      if (0x58 < uVar2) {
        return 0;
      }
      uVar2 = uVar2 - 0x40 & 0xff;
      bVar1 = (&r_modules_funcs_p)[uVar2 >> 3];
      goto _L17;
    }
  }
  else {
    if (*(short *)(param_1 + 4) != 0x1104) {
      return 0;
    }
    uVar2 = 0x3e;
  }
  if (((int)(uint)(byte)(&hci_env)[(uVar2 - 1 & 0xff) >> 3] >> (uVar2 - 1 & 7) & 1U) == 0) {
    return 1;
  }
  if (uVar2 != 0x3e) {
    return 0;
  }
  if (0xef < *(byte *)(param_1 + 0xc)) {
    return 0;
  }
  bVar1 = *(byte *)(param_1 + 0xc) - 1;
  uVar2 = (uint)bVar1;
  bVar1 = (&r_hli_funcs_p)[bVar1 >> 3];
_L17:
  return ~((int)(uint)bVar1 >> (uVar2 & 7)) & 1;
}

