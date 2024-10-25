/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
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
  
  iVar5 = (**(code **)(_r_ip_funcs_p + 0x830))
                    (1,param_1,param_2,param_3,*(code **)(_r_ip_funcs_p + 0x830));
  if (iVar5 != 0) {
    return;
  }
  (**(code **)(_r_ip_funcs_p + 0x7b0))(param_3,*(code **)(_r_ip_funcs_p + 0x7b0));
  if (_lld_init_env != 0) {
    iVar5 = *(int *)(_lld_init_env + param_1 * 4);
    if (iVar5 != 0) {
      cVar1 = *(char *)(iVar5 + 0x31);
      *(undefined1 *)(iVar5 + 0x31) = 0;
      bVar2 = *(byte *)(iVar5 + 0x52);
      if (cVar1 == '\x02') {
        while( true ) {
          iVar5 = (**(code **)(_r_ip_funcs_p + 0x2a4))
                            ((uint)bVar2,*(code **)(_r_ip_funcs_p + 0x2a4));
          if (iVar5 == 0) break;
          (**(code **)(_r_ip_funcs_p + 0x2a8))(*(code **)(_r_ip_funcs_p + 0x2a8));
        }
        (**(code **)(_r_ip_funcs_p + 0x454))(*(code **)(_r_ip_funcs_p + 0x454));
      }
      else {
        (**(code **)(_r_ip_funcs_p + 0x6b8))(iVar5,1,*(code **)(_r_ip_funcs_p + 0x6b8));
        iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
        iVar4 = (uint)bVar2 * 0x5a + 0x18;
        if ((*(ushort *)(iVar6 + iVar4) >> 10 & 1) != 0) {
          iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
          uVar3 = *(ushort *)(iVar6 + iVar4);
          iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
          *(ushort *)(iVar6 + iVar4) = uVar3 & 0xfbff;
          *(undefined1 *)(iVar5 + 0x3d) = 0;
        }
        (**(code **)(_r_ip_funcs_p + 0x474))(param_1,*(code **)(_r_ip_funcs_p + 0x474));
        (**(code **)(_r_ip_funcs_p + 0x484))(param_1,*(code **)(_r_ip_funcs_p + 0x484));
        if ((_lld_init_env != 0) && (*(int *)(param_1 * 4 + _lld_init_env) != 0)) {
          (**(code **)(_r_ip_funcs_p + 0x48c))
                    (param_1,param_2,param_3,*(code **)(_r_ip_funcs_p + 0x48c));
        }
      }
      goto _L198;
    }
  }
  (**(code **)(_r_plf_funcs_p + 0xc))(param_1,"lld_init.c",0x4c0,*(code **)(_r_plf_funcs_p + 0xc));
_L198:
                    /* WARNING: Could not recover jumptable at 0x0001147e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_ip_funcs_p + 0x830))(0,param_1,param_2,param_3);
  return;
}

