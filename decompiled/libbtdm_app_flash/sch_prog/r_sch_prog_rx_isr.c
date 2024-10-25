/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> sch_prog.o -> r_sch_prog_rx_isr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_sch_prog_rx_isr(void)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = (uint)DAT_00011100;
  iVar1 = r_emi_get_mem_addr_by_offset(0);
  iVar3 = uVar2 * 0x10;
  if ((*(ushort *)(iVar1 + iVar3) >> 3 & 6) == 0) {
    r_assert_err(0,"sch_prog.c",0x17a);
  }
  if (DAT_00011102 == '\0') {
    r_assert_err(0,"sch_prog.c",0x17e);
  }
  if (r_assert_param[iVar3] == (code)0x0) {
    r_assert_err(0,"sch_prog.c",0x181);
  }
  if (*(code **)(r_emi_get_mem_addr_by_offset + iVar3) != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x000102a2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(r_emi_get_mem_addr_by_offset + iVar3))
              (*(undefined4 *)(&sch_prog_env + iVar3),*(undefined4 *)(r_assert_err + iVar3),2);
    return;
  }
  return;
}

