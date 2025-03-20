/*
 * Last changed at upstream commit aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * https://github.com/espressif/esp32c3-bt-lib/commit/aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * Upstream date: 2025-03-20 20:31:24 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(d74042a8)
 * Source: libbtdm_app -> lld_scan.o -> r_lld_scan_frm_eof_isr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_scan_frm_eof_isr(int param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  byte bVar2;
  ushort uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  if ((_lld_scan_env == 0) || (iVar4 = *(int *)(param_1 * 4 + _lld_scan_env), iVar4 == 0)) {
                    /* WARNING: Could not recover jumptable at 0x00012e6c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_plf_funcs_p + 0xc))(_lld_scan_env,"lld_scan.c",0x98e);
    return;
  }
  cVar1 = *(char *)(iVar4 + 0x3c);
  *(undefined1 *)(iVar4 + 0x3c) = 0;
  bVar2 = *(byte *)(iVar4 + 0x38);
  if (cVar1 == '\x02') {
    while( true ) {
      iVar4 = (**(code **)(_r_ip_funcs_p + 0x2a4))((uint)bVar2,*(code **)(_r_ip_funcs_p + 0x2a4));
      if (iVar4 == 0) break;
      (**(code **)(_r_ip_funcs_p + 0x2a8))(*(code **)(_r_ip_funcs_p + 0x2a8));
    }
                    /* WARNING: Could not recover jumptable at 0x00012cea. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_ip_funcs_p + 0x3e4))();
    return;
  }
  (**(code **)(_r_ip_funcs_p + 0x6b8))(iVar4,1,*(code **)(_r_ip_funcs_p + 0x6b8));
  iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
  iVar5 = (uint)bVar2 * 0x5a + 0x18;
  if ((*(ushort *)(iVar6 + iVar5) >> 10 & 1) != 0) {
    iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar3 = *(ushort *)(iVar6 + iVar5);
    iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
    *(ushort *)(iVar5 + iVar6) = uVar3 & 0xfbff;
    if (*(char *)(iVar4 + 0x3d) == '\x03') {
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
      if (*(char *)(iVar5 + 0x18) == '\0') {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_scan.c",0x964,*(code **)(_r_plf_funcs_p + 8));
      }
      (**(code **)(_r_ip_funcs_p + 0x448))(param_1,*(code **)(_r_ip_funcs_p + 0x448));
    }
    *(undefined1 *)(iVar4 + 0x3e) = 0;
    *(undefined1 *)(iVar4 + 0x3d) = 0;
  }
  (**(code **)(_r_ip_funcs_p + 0x408))(param_1,*(code **)(_r_ip_funcs_p + 0x408));
  if ((*(char *)(iVar4 + 0x3e) == '\x02') ||
     ((*(char *)(iVar4 + 0x43) == '\0' && (*(char *)(iVar4 + 0x3e) == '\x01')))) {
    if (*(char *)(iVar4 + 0x3d) == '\x03') {
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
      if (*(char *)(iVar5 + 0x18) == '\0') {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_scan.c",0x978,*(code **)(_r_plf_funcs_p + 8));
      }
      (**(code **)(_r_ip_funcs_p + 0x448))(param_1,*(code **)(_r_ip_funcs_p + 0x448));
    }
    *(undefined1 *)(iVar4 + 0x3e) = 0;
  }
  else if (*(char *)(iVar4 + 0x3d) != '\x02') goto _L624;
  *(undefined1 *)(iVar4 + 0x3d) = 0;
_L624:
                    /* WARNING: Could not recover jumptable at 0x00012e3a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_ip_funcs_p + 0x430))(param_1,param_2,param_3);
  return;
}

