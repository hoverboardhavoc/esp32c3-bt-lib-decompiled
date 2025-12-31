/*
 * Last changed at upstream commit 16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * https://github.com/espressif/esp32c3-bt-lib/commit/16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * Upstream date: 2025-12-31 14:03:52 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(1bb2f50)
 * Source: libbtdm_app -> lld_sync.o -> r_lld_sync_frm_eof_isr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_sync_frm_eof_isr(int param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  code *pcVar6;
  int iVar7;
  
  iVar3 = (**(code **)(_r_ip_funcs_p + 0x850))
                    (1,param_1,param_2,param_3,*(code **)(_r_ip_funcs_p + 0x850));
  if (iVar3 == 0) {
    iVar3 = *(int *)(&lld_sync_env + param_1 * 4);
    if (iVar3 == 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0x10000,0x446,*(code **)(_r_plf_funcs_p + 8));
    }
    else {
      bVar1 = *(byte *)(iVar3 + 0x55);
      (**(code **)(_r_ip_funcs_p + 0x6b8))(iVar3,1,*(code **)(_r_ip_funcs_p + 0x6b8));
      iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      iVar7 = (uint)bVar1 * 0x5a + 0x18;
      if ((*(ushort *)(iVar4 + iVar7) >> 10 & 1) != 0) {
        iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
        uVar2 = *(ushort *)(iVar4 + iVar7);
        iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
        *(ushort *)(iVar4 + iVar7) = uVar2 & 0xfbff;
        if (*(char *)(iVar3 + 0x62) == '\x01') {
          (**(code **)(_r_ip_funcs_p + 0x178))(param_1,*(code **)(_r_ip_funcs_p + 0x178));
        }
        *(undefined1 *)(iVar3 + 99) = 0;
      }
      (**(code **)(_r_ip_funcs_p + 0x15c))(param_1,*(code **)(_r_ip_funcs_p + 0x15c));
      if (((*(char *)(iVar3 + 99) == '\x02') ||
          ((*(char *)(iVar3 + 100) == '\0' && (*(char *)(iVar3 + 99) == '\x01')))) &&
         (*(char *)(iVar3 + 0x62) == '\x01')) {
        (**(code **)(_r_ip_funcs_p + 0x178))(param_1,*(code **)(_r_ip_funcs_p + 0x178));
        *(undefined1 *)(iVar3 + 99) = 0;
      }
      if (*(char *)(iVar3 + 0x5b) == '\x02') {
        pcVar6 = *(code **)(_r_ip_funcs_p + 0x13c);
        uVar5 = 0;
      }
      else {
        pcVar6 = *(code **)(_r_ip_funcs_p + 0x16c);
        uVar5 = param_3;
      }
      (*pcVar6)(param_1,uVar5,pcVar6);
    }
                    /* WARNING: Could not recover jumptable at 0x0001127a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_ip_funcs_p + 0x850))
              (0,param_1,param_2,param_3,*(code **)(_r_ip_funcs_p + 0x850));
    return;
  }
  return;
}

