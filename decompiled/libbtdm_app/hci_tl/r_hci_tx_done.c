/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
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
  int iVar2;
  byte *pbVar3;
  
  iVar2 = _memcmp;
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  (**(code **)(_r_ip_funcs_p + 0xc))(iVar2,*(code **)(_r_ip_funcs_p + 0xc));
  memcpy = (code)0x1;
  uVar1 = *(ushort *)(iVar2 + 4);
  if (uVar1 < 0x1106) {
    if (0x1100 < uVar1) goto _L127;
  }
  else if (uVar1 == 0x1106) {
    (**(code **)(_r_modules_funcs_p + 0x40))(&hci_tl_env,*(code **)(_r_modules_funcs_p + 0x40));
    uVar1 = *(ushort *)(iVar2 + 0xc);
    pbVar3 = (byte *)(**(code **)(_r_plf_funcs_p + 0x20))(*(code **)(_r_plf_funcs_p + 0x20));
    if ((uVar1 & 0xfff) < (ushort)*pbVar3) {
      (**(code **)(_r_ip_funcs_p + 0x104))
                (*(undefined2 *)(iVar2 + 0x10),*(undefined4 *)(iVar2 + 0x14),
                 *(code **)(_r_ip_funcs_p + 0x104));
    }
    _memcmp = 0;
    (**(code **)(_r_ip_funcs_p + 0xb4))(*(code **)(_r_ip_funcs_p + 0xb4));
    goto _L127;
  }
  (**(code **)(_r_plf_funcs_p + 0xc))(0,"hci_tl.c",0x51f,*(code **)(_r_plf_funcs_p + 0xc));
_L127:
  if (_memcmp != 0) {
    iVar2 = (**(code **)(_r_modules_funcs_p + 0x40))
                      (&hci_tl_env,*(code **)(_r_modules_funcs_p + 0x40));
  }
  (**(code **)(_r_modules_funcs_p + 0xd8))(iVar2,*(code **)(_r_modules_funcs_p + 0xd8));
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
                    /* WARNING: Could not recover jumptable at 0x000109e6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_ip_funcs_p + 0x68))(*(code **)(_r_ip_funcs_p + 0x68));
  return;
}

