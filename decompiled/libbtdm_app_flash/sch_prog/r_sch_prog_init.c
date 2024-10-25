/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> sch_prog.o -> r_sch_prog_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_sch_prog_init(int param_1)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  
  if (param_1 - 1U < 2) {
    iVar2 = 0;
    memset(&sch_prog_env,0,0x104);
    do {
      iVar3 = r_emi_get_mem_addr_by_offset(0);
      uVar1 = *(ushort *)(iVar3 + iVar2);
      iVar3 = r_emi_get_mem_addr_by_offset(0);
      *(ushort *)(iVar3 + iVar2) = uVar1 & 0xffc7 | 0x18;
      iVar2 = iVar2 + 0x10;
    } while (iVar2 != 0x100);
    _LANCHOR0 = 0;
    return;
  }
  return;
}

