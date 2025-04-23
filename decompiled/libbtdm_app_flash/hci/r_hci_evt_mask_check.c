/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> hci.o -> r_hci_evt_mask_check
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint r_hci_evt_mask_check(int param_1)

{
  code cVar1;
  byte bVar2;
  uint uVar3;
  
  if (*(short *)(param_1 + 4) == 0x1103) {
    uVar3 = (uint)*(byte *)(param_1 + 8);
    if (0x3f < uVar3) {
      if (0x58 < uVar3) {
        return 0;
      }
      uVar3 = uVar3 - 0x40 & 0xff;
      cVar1 = (code)(&hci_ext_host)[uVar3 >> 3];
      goto _L12;
    }
  }
  else {
    if (*(short *)(param_1 + 4) != 0x1104) {
      return 0;
    }
    uVar3 = 0x3e;
  }
  if (((int)(uint)(byte)(&hci_env)[(uVar3 - 1 & 0xff) >> 3] >> (uVar3 - 1 & 7) & 1U) == 0) {
    return 1;
  }
  if (uVar3 != 0x3e) {
    return 0;
  }
  if (0xef < *(byte *)(param_1 + 0xc)) {
    return 0;
  }
  bVar2 = *(byte *)(param_1 + 0xc) - 1;
  uVar3 = (uint)bVar2;
  cVar1 = r_hci_look_for_cmd_desc[bVar2 >> 3];
_L12:
  return ~((int)(uint)(byte)cVar1 >> (uVar3 & 7)) & 1;
}

