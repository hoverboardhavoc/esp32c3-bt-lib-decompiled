/*
 * Last changed at upstream commit 2a91d90e33b3b1104daf1bff898fe5bc3f814811
 * https://github.com/espressif/esp32c3-bt-lib/commit/2a91d90e33b3b1104daf1bff898fe5bc3f814811
 * Upstream date: 2022-09-07 12:18:28 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(2ee0168e)
 * Source: libbtdm_app -> sch_prog.o -> r_sch_prog_end_isr_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_sch_prog_end_isr_hack(undefined4 param_1)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  ushort uVar5;
  uint uVar6;
  
  uVar2 = _DAT_60031054;
  bVar1 = false;
  if ((_DAT_60031060 & 0x20001) != 0) {
    _DAT_60031050 = 0x83828180;
    bVar1 = true;
    ble_do_master_soft_reset();
    if (1 < _g_bt_plf_log_level) {
      ets_printf("diag:%x,nb_prog:%x\n",uVar2,sch_prog_env);
    }
  }
  r_sch_prog_end_isr(param_1);
  if (bVar1) {
    while (DAT_00011106 != '\0') {
      uVar6 = (uint)DAT_00011104;
      iVar3 = uVar6 * 0x10;
      iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar5 = *(ushort *)(iVar4 + iVar3) >> 3 & 7;
      if (1 < _g_bt_plf_log_level) {
        iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0,*(code **)(_r_plf_funcs_p + 0xbc));
        ets_printf("et:%d,st:%x\n",uVar6,*(ushort *)(iVar4 + iVar3) >> 3 & 7);
      }
      switch(uVar5 - 1 & 0xff) {
      case 0:
        iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0,*(code **)(_r_plf_funcs_p + 0xbc));
        uVar5 = *(ushort *)(iVar4 + iVar3);
        iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0,*(code **)(_r_plf_funcs_p + 0xbc));
        *(ushort *)(iVar4 + iVar3) = uVar5 & 0xffc7 | 0x30;
      case 5:
        (**(code **)(_r_ip_funcs_p + 0x6d0))(0xff,*(code **)(_r_ip_funcs_p + 0x6d0));
        break;
      case 1:
        iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0,*(code **)(_r_plf_funcs_p + 0xbc));
        uVar5 = *(ushort *)(iVar4 + iVar3);
        iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0,*(code **)(_r_plf_funcs_p + 0xbc));
        *(ushort *)(iVar4 + iVar3) = uVar5 & 0xffc7 | 0x20;
      case 2:
      case 3:
      case 4:
        r_sch_prog_end_isr(0xff);
        break;
      default:
        (**(code **)(_r_plf_funcs_p + 0xc))
                  (uVar6,uVar5,"sch_prog.c",0xcb,*(code **)(_r_plf_funcs_p + 0xc));
      }
    }
  }
  return;
}

