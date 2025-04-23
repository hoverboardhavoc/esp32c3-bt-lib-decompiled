/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
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
  char cVar4;
  short sStack_12;
  
  sStack_12 = *(short *)(param_1 + 10);
  sVar1 = *(short *)(param_1 + 8);
  iVar2 = (**(code **)(_r_ip_funcs_p + 0x90))(sVar1,*(code **)(_r_ip_funcs_p + 0x90));
  if ((iVar2 == 0) || (sStack_12 == 0)) {
    if (sVar1 == 0) {
      (**(code **)(_r_plf_funcs_p + 0xc))
                (0,sStack_12,"hci_tl.c",0x22a,*(code **)(_r_plf_funcs_p + 0xc));
    }
    else {
      *(undefined1 *)(param_1 + 0xc) = 1;
    }
  }
  else {
    if (*(code **)(iVar2 + 8) == (code *)0x0) {
      uVar3 = 4;
    }
    else {
      if (*(char *)(iVar2 + 2) < '\0') {
        uVar3 = (**(code **)(iVar2 + 8))(param_1 + 0xc,&sStack_12,sStack_12);
        uVar3 = uVar3 & 0xff;
      }
      else {
        uVar3 = (**(code **)(_r_modules_funcs_p + 0x10))
                          (param_1 + 0xc,&sStack_12,sStack_12,*(code **)(_r_modules_funcs_p + 0x10))
        ;
      }
      if (uVar3 == 0) goto _L66;
    }
    (**(code **)(_r_plf_funcs_p + 0xc))
              (uVar3,sVar1,"hci_tl.c",0x220,*(code **)(_r_plf_funcs_p + 0xc));
  }
_L66:
  *(undefined1 *)(param_1 + 7) = 0xe;
  *(char *)(param_1 + 8) = (char)sStack_12 + '\x03';
  cVar4 = hci_tl_env;
  if (hci_tl_env < '\0') {
    cVar4 = '\0';
  }
  *(char *)(param_1 + 10) = (char)sVar1;
  *(char *)(param_1 + 9) = cVar4;
  *(char *)(param_1 + 0xb) = (char)((ushort)sVar1 >> 8);
  return param_1 + 7;
}

