/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> sch_prog.o -> r_sch_prog_et_state_reset
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_sch_prog_et_state_reset(void)

{
  int iVar1;
  char *pcVar2;
  int iVar3;
  code *pcVar4;
  uint uVar5;
  ushort uVar6;
  
  pcVar2 = (char *)(**(code **)(_r_ip_funcs_p + 0x920))(*(code **)(_r_ip_funcs_p + 0x920));
  if (*pcVar2 != '\0') {
_L23:
    while (DAT_00011106 != '\0') {
      uVar5 = (uint)DAT_00011104;
      iVar1 = uVar5 * 0x10;
      iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar6 = *(ushort *)(iVar3 + iVar1) >> 3 & 7;
      if (1 < _g_bt_plf_log_level) {
        iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0,*(code **)(_r_plf_funcs_p + 0xbc));
        ets_printf("et:%d,st:%x\n",uVar5,*(ushort *)(iVar3 + iVar1) >> 3 & 7);
      }
      switch(uVar6 - 1 & 0xff) {
      case 0:
        iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0,*(code **)(_r_plf_funcs_p + 0xbc));
        uVar6 = *(ushort *)(iVar3 + iVar1);
        iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0,*(code **)(_r_plf_funcs_p + 0xbc));
        *(ushort *)(iVar3 + iVar1) = uVar6 & 0xffc7 | 0x30;
      case 5:
        pcVar4 = *(code **)(_r_ip_funcs_p + 0x6d0);
        break;
      case 1:
        iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0,*(code **)(_r_plf_funcs_p + 0xbc));
        uVar6 = *(ushort *)(iVar3 + iVar1);
        iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0,*(code **)(_r_plf_funcs_p + 0xbc));
        *(ushort *)(iVar3 + iVar1) = uVar6 & 0xffc7 | 0x20;
      case 2:
      case 3:
      case 4:
        pcVar4 = *(code **)(_r_ip_funcs_p + 0x904);
        break;
      default:
        goto _L26;
      }
      (*pcVar4)(0xff,pcVar4);
    }
    *pcVar2 = '\0';
  }
  return;
_L26:
  (**(code **)(_r_plf_funcs_p + 0xc))
            (uVar5,uVar6,"sch_prog.c",0x130,*(code **)(_r_plf_funcs_p + 0xc));
  goto _L23;
}

