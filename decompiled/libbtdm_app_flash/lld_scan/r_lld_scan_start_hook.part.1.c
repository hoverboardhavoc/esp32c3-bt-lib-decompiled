/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> lld_scan.o -> r_lld_scan_start_hook.part.1
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_scan_start_hook_part_1(char *param_1,int param_2)

{
  short sVar1;
  undefined2 uVar2;
  ushort uVar3;
  ushort uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  int *piVar10;
  
  piVar10 = _lld_scan_env;
  if ((*param_1 == '\0') && (_lld_scan_env != (int *)0x0)) {
    iVar7 = r_ble_ll_qa_config_get();
    piVar9 = piVar10 + 2;
    do {
      if (*piVar10 != 0) {
        sVar1 = *(short *)(iVar7 + 0x14);
        uVar6 = (uint)*(byte *)(*piVar10 + 0x38);
        if ((sVar1 != 0) && (*(short *)(iVar7 + 0x16) != 0)) {
          iVar5 = uVar6 * 0x5a;
          iVar8 = r_emi_get_mem_addr_by_offset(0x400);
          *(short *)(iVar8 + iVar5 + 0xc) = sVar1;
          uVar2 = *(undefined2 *)(iVar7 + 0x16);
          iVar8 = r_emi_get_mem_addr_by_offset(0x400);
          *(undefined2 *)(iVar5 + 0xe + iVar8) = uVar2;
        }
        uVar3 = *(ushort *)(iVar7 + 0x18);
        if (uVar3 != 0) {
          if ((uVar3 & 0xc0) != 0) {
            r_assert_err(0,"lld_scan.c",0x3cf);
          }
          iVar8 = r_emi_get_mem_addr_by_offset(0x400);
          iVar5 = uVar6 * 0x5a + 0x16;
          uVar4 = *(ushort *)(iVar8 + iVar5);
          iVar8 = r_emi_get_mem_addr_by_offset(0x400);
          *(ushort *)(iVar5 + iVar8) = uVar4 & 0xffc0 | uVar3 & 0xff;
        }
      }
      piVar10 = piVar10 + 1;
    } while (piVar10 != piVar9);
  }
  lld_rpa_renew_start(*(undefined1 *)(param_2 + 0x12));
  return;
}

