/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> hci_tl.o -> r_hci_build_cc_evt
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int r_hci_build_cc_evt(int param_1)

{
  short sVar1;
  int iVar2;
  uint uVar3;
  short sVar4;
  undefined4 uVar5;
  char cVar6;
  short sStack_12;
  
  sVar1 = *(short *)(param_1 + 8);
  sStack_12 = *(short *)(param_1 + 10);
  iVar2 = r_hci_look_for_cmd_desc(sVar1);
  if ((iVar2 == 0) || (sStack_12 == 0)) {
    if (sVar1 != 0) {
      *(undefined1 *)(param_1 + 0xc) = 1;
      goto _L64;
    }
    uVar5 = 0x22a;
    uVar3 = 0;
    sVar4 = sStack_12;
  }
  else {
    if (*(code **)(iVar2 + 8) == (code *)0x0) {
      uVar3 = 4;
    }
    else {
      if (*(char *)(iVar2 + 2) < '\0') {
        uVar3 = (**(code **)(iVar2 + 8))(param_1 + 0xc,&sStack_12);
        uVar3 = uVar3 & 0xff;
      }
      else {
        uVar3 = r_co_util_pack();
      }
      if (uVar3 == 0) goto _L64;
    }
    uVar5 = 0x220;
    sVar4 = sVar1;
  }
  r_assert_param(uVar3,sVar4,"hci_tl.c",uVar5);
_L64:
  *(undefined1 *)(param_1 + 7) = 0xe;
  *(char *)(param_1 + 8) = (char)sStack_12 + '\x03';
  cVar6 = hci_tl_env;
  if (hci_tl_env < '\0') {
    cVar6 = '\0';
  }
  *(char *)(param_1 + 10) = (char)sVar1;
  *(char *)(param_1 + 0xb) = (char)((ushort)sVar1 >> 8);
  *(char *)(param_1 + 9) = cVar6;
  return param_1 + 7;
}

