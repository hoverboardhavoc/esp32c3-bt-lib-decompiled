/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app_flash -> lld_sync.o -> r_lld_sync_process_pkt_rx_pkt_check
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_sync_process_pkt_rx_pkt_check(uint param_1,int param_2)

{
  short sVar1;
  ushort uVar2;
  code *pcVar3;
  ushort uVar4;
  ushort uVar5;
  undefined1 uVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  undefined1 *puVar10;
  void *__src;
  undefined1 *puVar11;
  byte bVar12;
  ushort uVar13;
  uint uVar14;
  char cVar15;
  int iVar16;
  short sVar17;
  uint uVar18;
  uint uVar19;
  ushort uVar20;
  uint uVar21;
  int iVar22;
  undefined4 auStack_44 [4];
  
  uVar19 = (uint)*(byte *)(_p_lld_env + 0xd8);
  iVar16 = uVar19 * 0x14;
  iVar22 = *(int *)(&lld_sync_env + param_1 * 4);
  iVar7 = r_emi_get_mem_addr_by_offset(0x1000);
  uVar13 = *(ushort *)(iVar7 + iVar16 + 2);
  iVar7 = r_emi_get_mem_addr_by_offset(0x1000);
  sVar1 = *(short *)(iVar16 + 0x12 + iVar7);
  if ((uVar13 & 0x603d) != 0) {
    r_ble_log_internal_x1(0x20a5015a,param_1 << 0x10 | uVar19 << 0x18 | (uint)uVar13);
    return;
  }
  uVar21 = uVar19 << 8 | param_1;
  r_ble_log_internal_x1(0x20a50157,uVar21);
  iVar8 = r_emi_get_mem_addr_by_offset(0x1000);
  iVar7 = iVar16 + 4;
  uVar13 = *(ushort *)(iVar8 + iVar7);
  uVar9 = r_emi_get_mem_addr_by_offset(sVar1);
  r_ble_log_internal_hex(0x20a50158,uVar13 >> 8,uVar9);
  iVar8 = r_emi_get_mem_addr_by_offset(0x1000);
  if ((*(ushort *)(iVar8 + iVar7) & 0xf) != 7) {
    r_assert_err(0,0x10000,0x1d5);
  }
  *(undefined4 *)(iVar22 + 0x3c) = *(undefined4 *)(iVar22 + 0x44);
  *(char *)(iVar22 + 100) = *(char *)(iVar22 + 100) + '\x01';
  if (param_2 == 0) {
    *(char *)(iVar22 + 0x54) = *(char *)(iVar22 + 0x54) + '\x01';
  }
  iVar8 = r_emi_get_mem_addr_by_offset(0x1000);
  uVar13 = *(ushort *)(iVar8 + iVar16 + 0x10);
  iVar8 = r_emi_get_mem_addr_by_offset(0x1000);
  uVar5 = uVar13 & 0x3f;
  if (*(ushort *)(iVar8 + iVar7) >> 8 <= uVar5) {
    r_assert_err(0,0x10000,0x1e4);
  }
  cVar15 = '\0';
  if ((uVar13 & 0x3f) != 0) {
    cVar15 = (char)uVar5 + -1;
  }
  iVar8 = r_emi_get_mem_addr_by_offset(0x1000);
  uVar4 = *(ushort *)(iVar8 + iVar7);
  puVar10 = (undefined1 *)r_ke_msg_alloc(0x204,0,0xff,0x1c);
  *puVar10 = (char)param_1;
  *(undefined2 *)(puVar10 + 8) = *(undefined2 *)(iVar22 + 0x4a);
  uVar4 = (uVar4 >> 8) - uVar5 & 0xff;
  uVar20 = uVar4 - 1 & 0xff;
  if (*(char *)(iVar22 + 0x57) == '\0') {
    *(undefined1 *)(iVar22 + 0x57) = 1;
    puVar10[1] = *(undefined1 *)(iVar22 + 0x58);
    puVar10[2] = *(undefined1 *)(iVar22 + 0x59);
    uVar14 = *(uint *)(iVar22 + 0x40);
    uVar18 = *(uint *)(iVar22 + 0x44);
    *(short *)(puVar10 + 4) = (short)(uVar14 >> 2);
    uVar14 = uVar14 >> 1;
    if (uVar14 == 0) {
      r_assert_err(0,0x10000,0x94);
    }
    *(short *)(puVar10 + 6) = (short)((uVar18 >> 1) % uVar14);
    puVar10[10] = *(undefined1 *)(iVar22 + 0x5a);
    r_ble_log_internal_x2(0x40050159,*(undefined4 *)(iVar22 + 0x44),param_2 << 0x10 | uVar21);
  }
  else {
    uVar21 = *(uint *)(iVar22 + 0x40) >> 1;
    if (param_2 != 0) {
      uVar14 = *(uint *)(iVar22 + 0x44);
      if (uVar21 == 0) {
        r_assert_err(0,0x10000,0x94);
      }
      uVar21 = (uVar14 >> 1) % uVar21;
    }
    *(short *)(puVar10 + 6) = (short)uVar21;
  }
  iVar7 = r_emi_get_mem_addr_by_offset(0x1000);
  uVar2 = *(ushort *)(iVar7 + iVar16 + 0x10);
  if ((uVar13 & 0x3f) == 0) {
    *(undefined2 *)(iVar22 + 0x62) = 0;
  }
  else {
    sVar17 = 0;
    if ((uVar2 & 0x100) != 0) {
      sVar17 = 6;
    }
    if ((uVar2 & 0x200) != 0) {
      sVar17 = sVar17 + 6;
    }
    if ((uVar2 & 0x400) != 0) {
      sVar17 = sVar17 + 1;
    }
    if ((uVar2 >> 0xb & 1) != 0) {
      sVar17 = sVar17 + 2;
    }
    if ((uVar2 & 0x1000) == 0) {
      *(undefined2 *)(iVar22 + 0x62) = 0;
    }
    else {
      __src = (void *)r_emi_get_mem_addr_by_offset(sVar1 + sVar17);
      memcpy(auStack_44,__src,3);
      iVar7 = r_emi_get_mem_addr_by_offset(0x1000);
      uVar13 = *(ushort *)(iVar7 + iVar16 + 2);
      uVar6 = 2;
      bVar12 = (byte)(uVar13 >> 9) & 1;
      if ((uVar13 >> 9 & 1) == 0) {
        if ((*(byte *)(iVar22 + 0x54) < 7) &&
           (iVar7 = r_lld_calc_aux_rx(iVar22 + 0x24,uVar19,auStack_44[0]), iVar7 != 0)) {
          uVar6 = 1;
          bVar12 = 1;
        }
        else {
          uVar6 = 0;
          bVar12 = 2;
        }
      }
      *(undefined1 *)(iVar22 + 99) = uVar6;
      *(byte *)(iVar22 + 0x62) = bVar12;
      sVar17 = sVar17 + 3;
    }
    if ((uVar2 & 0x2000) != 0) {
      sVar17 = sVar17 + 0x12;
    }
    if ((uVar2 & 0x4000) != 0) {
      puVar11 = (undefined1 *)r_emi_get_mem_addr_by_offset(sVar1 + sVar17);
      sVar17 = sVar17 + 1;
      puVar10[0xb] = *puVar11;
    }
    if (param_2 == 0) {
      puVar10[0x19] = 0;
      puVar10[0x1a] = 0;
    }
    else {
      puVar10[0x19] = ((char)uVar5 + -1) - (char)sVar17;
      puVar10[0x1a] = (char)sVar17;
    }
  }
  pcVar3 = _r_lld_read_clock;
  iVar7 = r_emi_get_mem_addr_by_offset(0x1000);
  uVar6 = (*pcVar3)(*(ushort *)(iVar16 + 6 + iVar7) & 0xff);
  puVar10[0xc] = uVar6;
  uVar13 = *(short *)(iVar22 + 0x52) + uVar20;
  *(ushort *)(iVar22 + 0x52) = uVar13;
  if (0x672 < uVar13) {
    uVar20 = (uVar4 + 0x71) - uVar13 & 0xff;
    *(undefined2 *)(iVar22 + 0x62) = 2;
  }
  puVar10[0xe] = (char)uVar20;
  puVar10[0xd] = *(undefined1 *)(iVar22 + 0x62);
  if ((uVar20 != 0) || (puVar10[0x19] != '\0')) {
    *(short *)(puVar10 + 0x10) = sVar1;
    uVar9 = r_emi_get_mem_addr_by_offset(sVar1);
    iVar7 = _p_lld_env;
    *(undefined4 *)(puVar10 + 0x14) = uVar9;
    puVar10[0x18] = cVar15;
    bVar12 = *(byte *)(iVar7 + 0xd8);
    iVar7 = r_emi_get_mem_addr_by_offset(0x1000);
    *(undefined2 *)((uint)bVar12 * 0x14 + 0x12 + iVar7) = 0;
  }
  if (puVar10[0xd] == '\0') {
    uVar9 = 3;
  }
  else {
    uVar9 = 2;
    if (puVar10[0xd] != '\x02') goto _L115;
  }
  r_lld_sync_scan_dynamic_pti_process(iVar22,uVar9);
_L115:
  r_ke_msg_send(puVar10);
  return;
}

