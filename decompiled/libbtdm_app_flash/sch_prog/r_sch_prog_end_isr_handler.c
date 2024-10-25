/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> sch_prog.o -> r_sch_prog_end_isr_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_sch_prog_end_isr_handler(void)

{
  uint uVar1;
  int iVar2;
  ushort uVar3;
  int iVar4;
  
  uVar1 = (uint)DAT_00011100;
  iVar4 = uVar1 * 0x10;
  iVar2 = r_emi_get_mem_addr_by_offset(0);
  uVar3 = *(ushort *)(iVar2 + iVar4) >> 3 & 7;
  if (DAT_00011102 == '\0') {
    r_assert_err(0,"sch_prog.c",0xc6);
  }
  if (r_assert_param[iVar4] == (code)0x0) {
    r_assert_param(uVar3,uVar1,"sch_prog.c",0xc9);
  }
  if ((uVar3 - 3 & 0xff) < 3) {
    if (*(code **)(r_emi_get_mem_addr_by_offset + iVar4) == (code *)0x0) {
      r_assert_err(0,"sch_prog.c",0xe3);
    }
    else {
      (**(code **)(r_emi_get_mem_addr_by_offset + iVar4))
                (*(undefined4 *)(&sch_prog_env + iVar4),*(undefined4 *)(r_assert_err + iVar4),
                 uVar3 == 4);
    }
    r_assert_param[iVar4] = (code)0x0;
    DAT_00011102 = DAT_00011102 + -1;
    do {
      if (DAT_00011101 == uVar1) break;
      uVar1 = uVar1 + 1 & 0xf;
    } while (r_assert_param[uVar1 * 0x10] == (code)0x0);
    DAT_00011100 = (byte)uVar1;
  }
  if (DAT_00011102 == '\0') {
    r_rwip_prevent_sleep_clear(0x200);
    return;
  }
  return;
}

