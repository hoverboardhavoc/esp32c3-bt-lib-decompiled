/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
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
  int iVar6;
  code *pcVar7;
  
  iVar4 = _lld_rpa_renew_env;
  if (_lld_rpa_renew_env != 0) {
    iVar5 = 0;
    do {
      iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc60,*(code **)(_r_plf_funcs_p + 0xbc));
      if (*(short *)(iVar6 + iVar5) < 0) {
        iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc60,*(code **)(_r_plf_funcs_p + 0xbc));
        uVar1 = *(ushort *)(iVar6 + iVar5);
        iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc60,*(code **)(_r_plf_funcs_p + 0xbc));
        uVar2 = *(ushort *)(iVar6 + iVar5);
        iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc60,*(code **)(_r_plf_funcs_p + 0xbc));
        uVar3 = *(ushort *)(iVar6 + iVar5);
        iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc60,*(code **)(_r_plf_funcs_p + 0xbc));
        pcVar7 = *(code **)(_r_plf_funcs_p + 0xbc);
        *(ushort *)(iVar6 + iVar5) = (uVar1 & 0x20) << 1 | uVar3 & 0xffbf;
        iVar6 = (*pcVar7)(0xc60,pcVar7);
        uVar1 = *(ushort *)(iVar6 + iVar5);
        iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc60,*(code **)(_r_plf_funcs_p + 0xbc));
        *(ushort *)(iVar6 + iVar5) = (uVar2 & 2) << 1 | uVar1 & 0xfffb;
      }
      iVar5 = iVar5 + 0x34;
    } while (iVar5 != 0x208);
    (**(code **)(_r_ip_funcs_p + 0x6b8))(iVar4,1,*(code **)(_r_ip_funcs_p + 0x6b8));
    (**(code **)(_r_modules_funcs_p + 0x110))
              (_lld_rpa_renew_env,*(code **)(_r_modules_funcs_p + 0x110));
    _lld_rpa_renew_env = 0;
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x000115a8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_plf_funcs_p + 8))(0,"lld.c",0x46c,*(code **)(_r_plf_funcs_p + 8));
  return;
}

