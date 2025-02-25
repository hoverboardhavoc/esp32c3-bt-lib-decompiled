/*
 * Last changed at upstream commit 2ce747aec8008d008fe34fa375a2aea3e7e48e9a
 * https://github.com/espressif/esp32c3-bt-lib/commit/2ce747aec8008d008fe34fa375a2aea3e7e48e9a
 * Upstream date: 2025-02-25 15:16:47 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(723439d)
 * Source: libbtdm_app -> lld.o -> r_lld_rpa_renew_instant_cbk
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_rpa_renew_instant_cbk(void)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  int iVar4;
  int iVar5;
  code *pcVar6;
  int iVar7;
  
  iVar4 = _lld_rpa_renew_env;
  if (_lld_rpa_renew_env != 0) {
    iVar7 = 0;
    do {
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc60,*(code **)(_r_plf_funcs_p + 0xbc));
      if (*(short *)(iVar5 + iVar7) < 0) {
        iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc60,*(code **)(_r_plf_funcs_p + 0xbc));
        uVar1 = *(ushort *)(iVar5 + iVar7);
        iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc60,*(code **)(_r_plf_funcs_p + 0xbc));
        uVar2 = *(ushort *)(iVar5 + iVar7);
        iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc60,*(code **)(_r_plf_funcs_p + 0xbc));
        uVar3 = *(ushort *)(iVar5 + iVar7);
        iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc60,*(code **)(_r_plf_funcs_p + 0xbc));
        pcVar6 = *(code **)(_r_plf_funcs_p + 0xbc);
        *(ushort *)(iVar5 + iVar7) = (ushort)((uVar1 & 0x20) << 1) | uVar3 & 0xffbf;
        iVar5 = (*pcVar6)(0xc60,pcVar6);
        uVar1 = *(ushort *)(iVar5 + iVar7);
        iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc60,*(code **)(_r_plf_funcs_p + 0xbc));
        *(ushort *)(iVar5 + iVar7) = (ushort)((uVar2 & 2) << 1) | uVar1 & 0xfffb;
      }
      iVar7 = iVar7 + 0x34;
    } while (iVar7 != 0x208);
    (**(code **)(_r_ip_funcs_p + 0x6b8))(iVar4,1,*(code **)(_r_ip_funcs_p + 0x6b8));
    (**(code **)(_r_modules_funcs_p + 0x110))
              (_lld_rpa_renew_env,*(code **)(_r_modules_funcs_p + 0x110));
    _lld_rpa_renew_env = 0;
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x000115cc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_plf_funcs_p + 8))(0,"lld.c",0x46a);
  return;
}

