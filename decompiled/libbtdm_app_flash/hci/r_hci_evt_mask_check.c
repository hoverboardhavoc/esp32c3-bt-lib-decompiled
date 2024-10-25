/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
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
  byte bVar3;
  uint uVar4;
  uint uVar5;
  
  if (*(short *)(param_1 + 4) == 0x1103) {
    uVar4 = (uint)*(byte *)(param_1 + 8);
    if (0x3f < uVar4) {
      if (0x58 < uVar4) {
        return 0;
      }
      uVar4 = uVar4 - 0x40 & 0xff;
      cVar1 = (code)(&hci_ext_host)[uVar4 >> 3];
      goto _L12;
    }
  }
  else {
    if (*(short *)(param_1 + 4) != 0x1104) {
      return 0;
    }
    uVar4 = 0x3e;
  }
  uVar2 = (int)(uint)(byte)(&hci_env)[(uVar4 - 1 & 0xff) >> 3] >> (uVar4 - 1 & 7);
  uVar5 = ~uVar2 & 1;
  if ((uVar2 & 1) == 0) {
    return uVar5;
  }
  if (uVar4 != 0x3e) {
    return uVar5;
  }
  if (0xef < *(byte *)(param_1 + 0xc)) {
    return 0;
  }
  bVar3 = *(byte *)(param_1 + 0xc) - 1;
  uVar4 = (uint)bVar3;
  cVar1 = r_sdk_config_get_opts[bVar3 >> 3];
_L12:
  return ~((int)(uint)(byte)cVar1 >> (uVar4 & 7)) & 1;
}

