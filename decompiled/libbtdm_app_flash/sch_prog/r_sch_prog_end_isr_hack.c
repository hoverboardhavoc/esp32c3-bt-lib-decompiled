/*
 * Last changed at upstream commit 72599d583c232ea78d6461b5b502426c6e5a1ec9
 * https://github.com/espressif/esp32c3-bt-lib/commit/72599d583c232ea78d6461b5b502426c6e5a1ec9
 * Upstream date: 2025-05-19 16:27:45 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(6cfabcd8)
 * Source: libbtdm_app_flash -> sch_prog.o -> r_sch_prog_end_isr_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_sch_prog_end_isr_hack(undefined4 param_1)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  r_sch_prog_hw_reset_try();
  r_sch_prog_end_isr_handler(param_1);
  if (sch_prog_state != '\0') {
    while (DAT_00011102 != '\0') {
      uVar4 = (uint)DAT_00011100;
      iVar3 = r_emi_get_mem_addr_by_offset(0);
      iVar2 = uVar4 * 0x10;
      uVar1 = *(ushort *)(iVar3 + iVar2) >> 3 & 7;
      if (1 < _g_bt_plf_log_level) {
        iVar3 = r_emi_get_mem_addr_by_offset(0);
        ets_printf("et:%d,st:%x\n",uVar4,*(ushort *)(iVar3 + iVar2) >> 3 & 7);
      }
      if (uVar1 < 6) {
        if (uVar1 < 3) {
          if (uVar1 == 1) {
            iVar3 = r_emi_get_mem_addr_by_offset(0);
            uVar1 = *(ushort *)(iVar3 + iVar2);
            iVar3 = r_emi_get_mem_addr_by_offset(0);
            *(ushort *)(iVar3 + iVar2) = uVar1 & 0xffc7 | 0x30;
            goto _L66;
          }
          if (uVar1 != 2) goto _L65;
          iVar3 = r_emi_get_mem_addr_by_offset(0);
          uVar1 = *(ushort *)(iVar3 + iVar2);
          iVar3 = r_emi_get_mem_addr_by_offset(0);
          *(ushort *)(iVar2 + iVar3) = uVar1 & 0xffc7 | 0x20;
        }
        r_sch_prog_end_isr_handler(0xff);
      }
      else if (uVar1 == 6) {
_L66:
        r_sch_prog_skip_isr(0xff);
      }
      else {
_L65:
        r_assert_param(uVar4,uVar1,"sch_prog.c",0x130);
      }
    }
    sch_prog_state = '\0';
  }
  return;
}

