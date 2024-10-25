/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> hci_tl.o -> r_hci_build_evt
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int r_hci_build_evt(int param_1)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  ushort uVar4;
  ushort auStack_22 [7];
  
  auStack_22[0] = *(ushort *)(param_1 + 10);
  uVar1 = *(ushort *)(param_1 + 8);
  uVar4 = uVar1 & 0xff;
  if (0xff < uVar1) {
    r_assert_param(0,"hci_tl.c",0x24f);
  }
  iVar2 = r_hci_look_for_evt_desc(uVar4);
  if (iVar2 == 0) {
    r_assert_param(uVar4,0,"hci_tl.c",0x278);
    return param_1 + 10;
  }
  if (*(code **)(iVar2 + 4) == (code *)0x0) {
    if (*(short *)(param_1 + 10) != 0) {
      uVar3 = 4;
      goto _L85;
    }
  }
  else {
    if (*(char *)(iVar2 + 2) == '\0') {
      uVar3 = r_co_util_pack();
    }
    else {
      uVar3 = (**(code **)(iVar2 + 4))(param_1 + 0xc,auStack_22,auStack_22[0]);
      uVar3 = uVar3 & 0xff;
    }
    if (uVar3 != 0) {
_L85:
      r_assert_param(uVar3,uVar4,"hci_tl.c",0x26b);
      goto _L86;
    }
  }
  uVar3 = 0;
_L86:
  if (*(ushort *)(param_1 + 10) < auStack_22[0]) {
    r_assert_param(uVar3,uVar4,"hci_tl.c",0x26e);
  }
  *(char *)(param_1 + 10) = (char)uVar1;
  *(char *)(param_1 + 0xb) = (char)auStack_22[0];
  return param_1 + 10;
}

