/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> hci_tl.o -> r_hci_build_cc_evt
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int r_hci_build_cc_evt(int param_1)

{
  short sVar1;
  int iVar2;
  uint uVar3;
  short sVar4;
  undefined4 uVar5;
  char cVar6;
  code *pcVar7;
  short sStack_12;
  
  sStack_12 = *(short *)(param_1 + 10);
  sVar1 = *(short *)(param_1 + 8);
  iVar2 = (**(code **)(_r_ip_funcs_p + 0x90))(sVar1,*(code **)(_r_ip_funcs_p + 0x90));
  if ((iVar2 == 0) || (sStack_12 == 0)) {
    if (sVar1 != 0) {
      *(undefined1 *)(param_1 + 0xc) = 1;
      goto _L65;
    }
    uVar5 = 0x22a;
    pcVar7 = *(code **)(_r_plf_funcs_p + 0xc);
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
        uVar3 = (**(code **)(_r_modules_funcs_p + 0x10))
                          (param_1 + 0xc,&sStack_12,*(code **)(_r_modules_funcs_p + 0x10));
      }
      if (uVar3 == 0) goto _L65;
    }
    uVar5 = 0x220;
    pcVar7 = *(code **)(_r_plf_funcs_p + 0xc);
    sVar4 = sVar1;
  }
  (*pcVar7)(uVar3,sVar4,"hci_tl.c",uVar5,pcVar7);
_L65:
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

