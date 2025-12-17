/*
 * Last changed at upstream commit 9b50531537e755792ac827d00d233eab499a0b37
 * https://github.com/espressif/esp32c3-bt-lib/commit/9b50531537e755792ac827d00d233eab499a0b37
 * Upstream date: 2025-12-17 10:51:37 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(5106725)
 * Source: libbtdm_app_flash -> lld_con.o -> r_lld_con_tx_isr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_con_tx_isr(int param_1)

{
  byte bVar1;
  byte bVar2;
  ushort uVar3;
  bool bVar4;
  int iVar5;
  int iVar6;
  undefined1 *puVar7;
  undefined1 uVar8;
  int iVar9;
  
  if (*(int *)(&lld_con_env + param_1 * 4) == 0) {
    r_assert_param(0,"lld_con.c",0xc83);
    return;
  }
  r_lld_con_tx_eco();
  iVar5 = *(int *)(&lld_con_env + param_1 * 4);
  if (*(int *)(iVar5 + 0x30) == 0) {
    iVar9 = *(int *)(iVar5 + 0x28);
    *(int *)(iVar5 + 0x30) = iVar9;
    if (iVar9 != 0) {
      *(ushort *)(iVar5 + 0x82) = *(ushort *)(iVar9 + 6) & 0x3ff;
    }
  }
  bVar4 = false;
  if ((((*(ushort *)(iVar5 + 0x84) & 0x10) != 0) && (*(int **)(iVar5 + 0x30) != (int *)0x0)) &&
     (bVar4 = true, *(short *)(iVar5 + 0x82) == 0)) {
    bVar4 = **(int **)(iVar5 + 0x30) != 0;
  }
  iVar9 = *(int *)(iVar5 + 0x24);
  if ((iVar9 != 0) || (bVar4)) {
    if (*(char *)(iVar5 + 0x92) == '\x02') {
      bVar1 = *(byte *)(iVar5 + 0x8e);
      bVar2 = *(byte *)(iVar5 + 0x91);
      iVar6 = r_emi_get_mem_addr_by_offset(0x1400);
      iVar9 = ((bVar2 + 1 & 1) + (uint)bVar1 * 9 & 0xff) * 0xe;
      if (-1 < *(short *)(iVar6 + iVar9)) {
        iVar6 = r_emi_get_mem_addr_by_offset(0x1400);
        iVar9 = iVar9 + 2;
        uVar3 = *(ushort *)(iVar6 + iVar9);
        iVar6 = r_emi_get_mem_addr_by_offset(0x1400);
        *(ushort *)(iVar9 + iVar6) = uVar3 & 0xffef | 0x10;
      }
    }
    else {
      uVar8 = 0x23;
      if (iVar9 != 0) {
        puVar7 = (undefined1 *)r_emi_get_mem_addr_by_offset(*(undefined2 *)(iVar9 + 4),0x23);
        uVar8 = *puVar7;
      }
      r_lld_con_tx_prog_new_packet_hack(param_1,uVar8);
    }
  }
  r_ble_log_internal_x3
            (0x20e30088,*(undefined4 *)(iVar5 + 0x24),*(undefined4 *)(iVar5 + 0x30),
             (uint)*(ushort *)(iVar5 + 0x82) | param_1 << 0x10 |
             (uint)*(byte *)(iVar5 + 0x92) << 0x18);
  return;
}

