/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> hci_tl.o -> r_hci_tx_done
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_hci_tx_done(void)

{
  ushort uVar1;
  byte *pbVar2;
  int iVar3;
  
  iVar3 = _memcmp;
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  (**(code **)(_r_ip_funcs_p + 0xc))(iVar3,*(code **)(_r_ip_funcs_p + 0xc));
  memcpy = (code)0x1;
  uVar1 = *(ushort *)(iVar3 + 4);
  if (uVar1 < 0x1106) {
    if (0x1100 < uVar1) goto _L134;
  }
  else if (uVar1 == 0x1106) {
    (**(code **)(_r_modules_funcs_p + 0x40))(&hci_tl_env,*(code **)(_r_modules_funcs_p + 0x40));
    uVar1 = *(ushort *)(iVar3 + 0xc);
    pbVar2 = (byte *)(**(code **)(_r_plf_funcs_p + 0x20))(*(code **)(_r_plf_funcs_p + 0x20));
    if ((uVar1 & 0xfff) < (ushort)*pbVar2) {
      (**(code **)(_r_ip_funcs_p + 0x104))
                (*(undefined2 *)(iVar3 + 0x10),*(undefined4 *)(iVar3 + 0x14),
                 *(code **)(_r_ip_funcs_p + 0x104));
    }
    _memcmp = 0;
    (**(code **)(_r_ip_funcs_p + 0xb4))(*(code **)(_r_ip_funcs_p + 0xb4));
    goto _L134;
  }
  (**(code **)(_r_plf_funcs_p + 0xc))(0,"hci_tl.c",0x51f,*(code **)(_r_plf_funcs_p + 0xc));
_L134:
  if (_memcmp != 0) {
    iVar3 = (**(code **)(_r_modules_funcs_p + 0x40))
                      (&hci_tl_env,*(code **)(_r_modules_funcs_p + 0x40));
  }
  (**(code **)(_r_modules_funcs_p + 0xd8))(iVar3,*(code **)(_r_modules_funcs_p + 0xd8));
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
                    /* WARNING: Could not recover jumptable at 0x00010a82. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_ip_funcs_p + 0x68))(*(code **)(_r_ip_funcs_p + 0x68));
  return;
}

