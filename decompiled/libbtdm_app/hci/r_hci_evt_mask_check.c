/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> hci.o -> r_hci_evt_mask_check
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint r_hci_evt_mask_check(int param_1)

{
  uint uVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  
  if (*(short *)(param_1 + 4) == 0x1103) {
    uVar3 = (uint)*(byte *)(param_1 + 8);
    if (0x3f < uVar3) {
      if (0x58 < uVar3) {
        return 0;
      }
      uVar3 = uVar3 - 0x40 & 0xff;
      bVar2 = (&r_modules_funcs_p)[uVar3 >> 3];
      goto _L17;
    }
  }
  else {
    if (*(short *)(param_1 + 4) != 0x1104) {
      return 0;
    }
    uVar3 = 0x3e;
  }
  uVar1 = (int)(uint)(byte)(&hci_env)[(uVar3 - 1 & 0xff) >> 3] >> (uVar3 - 1 & 7);
  uVar4 = ~uVar1 & 1;
  if ((uVar1 & 1) == 0) {
    return uVar4;
  }
  if (uVar3 != 0x3e) {
    return uVar4;
  }
  if (0xef < *(byte *)(param_1 + 0xc)) {
    return 0;
  }
  bVar2 = *(byte *)(param_1 + 0xc) - 1;
  uVar3 = (uint)bVar2;
  bVar2 = (&r_hli_funcs_p)[bVar2 >> 3];
_L17:
  return ~((int)(uint)bVar2 >> (uVar3 & 7)) & 1;
}

