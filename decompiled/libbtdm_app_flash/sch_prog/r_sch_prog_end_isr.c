/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> sch_prog.o -> r_sch_prog_end_isr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_sch_prog_end_isr(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  ushort uVar4;
  
  r_sch_prog_hw_reset_try();
  r_sch_prog_end_isr_handler(param_1);
  if (sch_prog_state != '\0') {
    while (DAT_00011102 != '\0') {
      uVar3 = (uint)DAT_00011100;
      iVar2 = r_emi_get_mem_addr_by_offset(0);
      iVar1 = uVar3 * 0x10;
      uVar4 = *(ushort *)(iVar2 + iVar1) >> 3 & 7;
      if (1 < _g_bt_plf_log_level) {
        iVar2 = r_emi_get_mem_addr_by_offset(0);
        ets_printf("et:%d,st:%x\n",uVar3,*(ushort *)(iVar2 + iVar1) >> 3 & 7);
      }
      switch(uVar4 - 1 & 0xff) {
      case 0:
        iVar2 = r_emi_get_mem_addr_by_offset(0);
        uVar4 = *(ushort *)(iVar2 + iVar1);
        iVar2 = r_emi_get_mem_addr_by_offset(0);
        *(ushort *)(iVar2 + iVar1) = uVar4 & 0xffc7 | 0x30;
      case 5:
        r_sch_prog_skip_isr(0xff);
        break;
      case 1:
        iVar2 = r_emi_get_mem_addr_by_offset(0);
        uVar4 = *(ushort *)(iVar2 + iVar1);
        iVar2 = r_emi_get_mem_addr_by_offset(0);
        *(ushort *)(iVar2 + iVar1) = uVar4 & 0xffc7 | 0x20;
      case 2:
      case 3:
      case 4:
        r_sch_prog_end_isr_handler(0xff);
        break;
      default:
        r_assert_param(uVar3,uVar4,"sch_prog.c",0x130);
      }
    }
    sch_prog_state = '\0';
  }
  return;
}

