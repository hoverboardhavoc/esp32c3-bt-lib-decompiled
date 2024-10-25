/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> lld_init.o -> r_lld_init_process_pkt_rx
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_init_process_pkt_rx(int param_1)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  code *pcVar6;
  ushort uVar7;
  
  iVar2 = _lld_init_env;
  if ((_lld_init_env == 0) || (iVar3 = *(int *)(param_1 * 4 + _lld_init_env), iVar3 == 0)) {
                    /* WARNING: Could not recover jumptable at 0x00010f44. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_init.c",0x39a);
    return;
  }
  do {
    iVar4 = (**(code **)(_r_ip_funcs_p + 0x2a4))
                      (*(undefined1 *)(iVar3 + 0x52),*(code **)(_r_ip_funcs_p + 0x2a4));
    if (iVar4 == 0) {
      if ((*(char *)(iVar3 + 0x3d) == '\x02') ||
         ((*(char *)(iVar3 + 0x50) == '\0' && (*(char *)(iVar3 + 0x3d) == '\x01')))) {
        *(undefined1 *)(iVar3 + 0x3d) = 0;
      }
      return;
    }
    iVar4 = (uint)*(byte *)(_p_lld_env + 0xd8) * 0x14;
    iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
    if (((*(ushort *)(iVar5 + iVar4 + 2) & 0x603d) == 0) && (*(char *)(iVar2 + 0x50) == '\0')) {
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar7 = *(ushort *)(iVar5 + iVar4 + 4);
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar1 = *(undefined2 *)(iVar5 + iVar4 + 0x12);
      *(undefined1 *)(iVar3 + 0x50) = 1;
      if ((uVar7 & 0xe) == 0) {
        pcVar6 = *(code **)(_r_ip_funcs_p + 0x478);
        goto _L150;
      }
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
      if (*(char *)(iVar5 + 0x18) != '\0') {
        uVar7 = uVar7 & 0xf;
        iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
        if (uVar7 == 7) {
          if ((*(ushort *)(iVar4 + 0x10 + iVar5) & 0x40) != 0) {
            pcVar6 = *(code **)(_r_ip_funcs_p + 0x47c);
_L150:
            (*pcVar6)(param_1,uVar1,pcVar6);
          }
        }
        else if (uVar7 == 8) {
          pcVar6 = *(code **)(_r_ip_funcs_p + 0x480);
          goto _L150;
        }
      }
    }
    (**(code **)(_r_ip_funcs_p + 0x2a8))(*(code **)(_r_ip_funcs_p + 0x2a8));
  } while( true );
}

