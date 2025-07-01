/*
 * Last changed at upstream commit 0c68809d62e432427de97b5294f6619307f62f40
 * https://github.com/espressif/esp32c3-bt-lib/commit/0c68809d62e432427de97b5294f6619307f62f40
 * Upstream date: 2025-07-01 15:07:54 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2edb0b0)
 * Source: libbtdm_app_flash -> sch_prog.o -> r_sch_prog_end_isr_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_sch_prog_end_isr_hack(undefined4 param_1)

{
  int iVar1;
  ushort uVar2;
  int iVar3;
  uint uVar4;
  
  r_sch_prog_hw_reset_try();
  r_sch_prog_end_isr_handler(param_1);
  if (sch_prog_state != '\0') {
    while (DAT_00011102 != '\0') {
      uVar4 = (uint)DAT_00011100;
      iVar3 = r_emi_get_mem_addr_by_offset(0);
      iVar1 = uVar4 * 0x10;
      uVar2 = *(ushort *)(iVar3 + iVar1) >> 3 & 7;
      if (1 < _g_bt_plf_log_level) {
        iVar3 = r_emi_get_mem_addr_by_offset(0);
        ets_printf("et:%d,st:%x\n",uVar4,*(ushort *)(iVar3 + iVar1) >> 3 & 7);
      }
      if (uVar2 < 6) {
        if (uVar2 < 3) {
          if (uVar2 != 2) {
            iVar3 = r_emi_get_mem_addr_by_offset(0);
            uVar2 = *(ushort *)(iVar3 + iVar1);
            iVar3 = r_emi_get_mem_addr_by_offset(0);
            *(ushort *)(iVar3 + iVar1) = uVar2 & 0xffc7 | 0x30;
            goto _L65;
          }
          iVar3 = r_emi_get_mem_addr_by_offset(0);
          uVar2 = *(ushort *)(iVar3 + iVar1);
          iVar3 = r_emi_get_mem_addr_by_offset(0);
          *(ushort *)(iVar1 + iVar3) = uVar2 & 0xffc7 | 0x20;
        }
        r_sch_prog_end_isr_handler(0xff);
      }
      else if (uVar2 == 6) {
_L65:
        r_sch_prog_skip_isr(0xff);
      }
      else {
        r_assert_param(uVar4,7,"sch_prog.c",0x132);
      }
    }
    sch_prog_state = '\0';
  }
  return;
}

