/*
 * Last changed at upstream commit 16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * https://github.com/espressif/esp32c3-bt-lib/commit/16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * Upstream date: 2025-12-31 14:03:52 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(1bb2f50)
 * Source: libbtdm_app -> lld_init.o -> r_lld_init_frm_eof_isr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_init_frm_eof_isr(int param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  byte bVar2;
  ushort uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar4 = (**(code **)(_r_ip_funcs_p + 0x830))
                    (1,param_1,param_2,param_3,*(code **)(_r_ip_funcs_p + 0x830));
  if (iVar4 != 0) {
    return;
  }
  (**(code **)(_r_ip_funcs_p + 0x7b0))(param_3,*(code **)(_r_ip_funcs_p + 0x7b0));
  if (_lld_init_env != 0) {
    iVar4 = *(int *)(_lld_init_env + param_1 * 4);
    if (iVar4 != 0) {
      cVar1 = *(char *)(iVar4 + 0x31);
      *(undefined1 *)(iVar4 + 0x31) = 0;
      bVar2 = *(byte *)(iVar4 + 0x52);
      if (cVar1 == '\x02') {
        while( true ) {
          iVar4 = (**(code **)(_r_ip_funcs_p + 0x2a4))
                            ((uint)bVar2,*(code **)(_r_ip_funcs_p + 0x2a4));
          if (iVar4 == 0) break;
          (**(code **)(_r_ip_funcs_p + 0x2a8))(*(code **)(_r_ip_funcs_p + 0x2a8));
        }
        (**(code **)(_r_ip_funcs_p + 0x454))(*(code **)(_r_ip_funcs_p + 0x454));
      }
      else {
        (**(code **)(_r_ip_funcs_p + 0x6b8))(iVar4,1,*(code **)(_r_ip_funcs_p + 0x6b8));
        iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
        iVar6 = (uint)bVar2 * 0x5a + 0x18;
        if ((*(ushort *)(iVar5 + iVar6) >> 10 & 1) != 0) {
          iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
          uVar3 = *(ushort *)(iVar5 + iVar6);
          iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
          *(ushort *)(iVar5 + iVar6) = uVar3 & 0xfbff;
          *(undefined1 *)(iVar4 + 0x3d) = 0;
        }
        (**(code **)(_r_ip_funcs_p + 0x474))(param_1,*(code **)(_r_ip_funcs_p + 0x474));
        (**(code **)(_r_ip_funcs_p + 0x484))(param_1,*(code **)(_r_ip_funcs_p + 0x484));
        if ((_lld_init_env != 0) && (*(int *)(_lld_init_env + param_1 * 4) != 0)) {
          (**(code **)(_r_ip_funcs_p + 0x48c))
                    (param_1,param_2,param_3,*(code **)(_r_ip_funcs_p + 0x48c));
        }
      }
      goto _L197;
    }
  }
  (**(code **)(_r_plf_funcs_p + 0xc))(param_1,0x10000,0x4f3,*(code **)(_r_plf_funcs_p + 0xc));
_L197:
                    /* WARNING: Could not recover jumptable at 0x00011458. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_ip_funcs_p + 0x830))(0,param_1,param_2,param_3,*(code **)(_r_ip_funcs_p + 0x830));
  return;
}

