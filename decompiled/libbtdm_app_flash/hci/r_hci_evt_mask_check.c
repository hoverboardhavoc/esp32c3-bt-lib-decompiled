/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app_flash -> hci.o -> r_hci_evt_mask_check
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint r_hci_evt_mask_check(int param_1)

{
  code cVar1;
  uint uVar2;
  uint uVar3;
  byte bVar4;
  uint uVar5;
  
  if (*(short *)(param_1 + 4) == 0x1103) {
    uVar5 = (uint)*(byte *)(param_1 + 8);
    if (0x3f < uVar5) {
      if (0x58 < uVar5) {
        return 0;
      }
      uVar5 = uVar5 - 0x40 & 0xff;
      cVar1 = r_ke_msg_free[uVar5 >> 3];
      goto _L12;
    }
  }
  else {
    if (*(short *)(param_1 + 4) != 0x1104) {
      return 0;
    }
    uVar5 = 0x3e;
  }
  uVar3 = (int)(uint)(byte)(&hci_env)[(uVar5 - 1 & 0xff) >> 3] >> (uVar5 - 1 & 7) & 1;
  uVar2 = uVar3 ^ 1;
  if (uVar3 == 0) {
    return uVar2;
  }
  if (uVar5 != 0x3e) {
    return uVar2;
  }
  if (0xef < *(byte *)(param_1 + 0xc)) {
    return 0;
  }
  bVar4 = *(byte *)(param_1 + 0xc) - 1;
  uVar5 = (uint)bVar4;
  cVar1 = r_sdk_config_get_opts[bVar4 >> 3];
_L12:
  return ~((int)(uint)(byte)cVar1 >> (uVar5 & 7)) & 1;
}

