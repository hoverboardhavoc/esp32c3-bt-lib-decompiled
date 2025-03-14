/*
 * Last changed at upstream commit e668c2d101ee46ee1950819607694fb852aecae0
 * https://github.com/espressif/esp32c3-bt-lib/commit/e668c2d101ee46ee1950819607694fb852aecae0
 * Upstream date: 2025-03-14 11:07:43 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(6e312587)
 * Source: libbtdm_app_flash -> lld_sync.o -> r_lld_sync_process_pkt_rx_pkt_check
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_sync_process_pkt_rx_pkt_check(int param_1,int param_2)

{
  byte bVar1;
  short sVar2;
  ushort uVar3;
  code *pcVar4;
  int iVar5;
  ushort uVar6;
  undefined1 uVar7;
  int iVar8;
  int iVar9;
  undefined1 *puVar10;
  void *__src;
  undefined1 *puVar11;
  undefined4 uVar12;
  undefined2 uVar13;
  ushort uVar14;
  uint uVar15;
  ushort uVar16;
  int iVar17;
  char cVar18;
  short sVar19;
  uint uVar20;
  undefined4 auStack_44 [4];
  
  iVar5 = *(int *)(&lld_sync_env + param_1 * 4);
  bVar1 = *(byte *)(_p_lld_env + 0xd8);
  iVar17 = (uint)bVar1 * 0x14;
  iVar8 = r_emi_get_mem_addr_by_offset(0x1000);
  uVar14 = *(ushort *)(iVar8 + iVar17 + 2);
  iVar8 = r_emi_get_mem_addr_by_offset(0x1000);
  sVar2 = *(short *)(iVar8 + iVar17 + 0x12);
  if ((uVar14 & 0x603d) != 0) {
    return;
  }
  iVar9 = r_emi_get_mem_addr_by_offset(0x1000);
  iVar8 = iVar17 + 4;
  if ((*(ushort *)(iVar9 + iVar8) & 0xf) != 7) {
    r_assert_err(0,"lld_sync.c",0x1c8);
  }
  *(undefined4 *)(iVar5 + 0x3c) = *(undefined4 *)(iVar5 + 0x44);
  *(char *)(iVar5 + 100) = *(char *)(iVar5 + 100) + '\x01';
  if (param_2 == 0) {
    *(char *)(iVar5 + 0x54) = *(char *)(iVar5 + 0x54) + '\x01';
  }
  iVar9 = r_emi_get_mem_addr_by_offset(0x1000);
  uVar14 = *(ushort *)(iVar9 + iVar17 + 0x10);
  iVar9 = r_emi_get_mem_addr_by_offset(0x1000);
  uVar16 = uVar14 & 0x3f;
  if (*(ushort *)(iVar9 + iVar8) >> 8 <= uVar16) {
    r_assert_err(0,"lld_sync.c",0x1d7);
  }
  cVar18 = '\0';
  if ((uVar14 & 0x3f) != 0) {
    cVar18 = (char)uVar16 + -1;
  }
  iVar9 = r_emi_get_mem_addr_by_offset(0x1000);
  uVar6 = *(ushort *)(iVar9 + iVar8);
  puVar10 = (undefined1 *)r_ke_msg_alloc(0x204,0,0xff,0x1c);
  *puVar10 = (char)param_1;
  uVar6 = (uVar6 >> 8) + ~uVar16 & 0xff;
  *(undefined2 *)(puVar10 + 8) = *(undefined2 *)(iVar5 + 0x4a);
  if (*(char *)(iVar5 + 0x57) == '\0') {
    *(undefined1 *)(iVar5 + 0x57) = 1;
    puVar10[1] = *(undefined1 *)(iVar5 + 0x58);
    puVar10[2] = *(undefined1 *)(iVar5 + 0x59);
    uVar15 = *(uint *)(iVar5 + 0x40);
    uVar20 = *(uint *)(iVar5 + 0x44);
    *(short *)(puVar10 + 4) = (short)(uVar15 >> 2);
    uVar15 = uVar15 >> 1;
    if (uVar15 == 0) {
      r_assert_err(0,"lld_sync.c",0x94);
    }
    *(short *)(puVar10 + 6) = (short)((uVar20 >> 1) % uVar15);
    puVar10[10] = *(undefined1 *)(iVar5 + 0x5a);
  }
  else {
    uVar15 = *(uint *)(iVar5 + 0x40) >> 1;
    if (param_2 != 0) {
      uVar20 = *(uint *)(iVar5 + 0x44);
      if (uVar15 == 0) {
        r_assert_err(0,"lld_sync.c",0x94);
      }
      uVar15 = (uVar20 >> 1) % uVar15;
    }
    *(short *)(puVar10 + 6) = (short)uVar15;
  }
  iVar8 = r_emi_get_mem_addr_by_offset(0x1000);
  uVar3 = *(ushort *)(iVar8 + iVar17 + 0x10);
  uVar15 = (uint)uVar3;
  if ((uVar14 & 0x3f) == 0) {
    *(undefined2 *)(iVar5 + 0x62) = 0;
  }
  else {
    sVar19 = 0;
    if ((uVar3 & 0x100) != 0) {
      sVar19 = 6;
    }
    if ((uVar3 & 0x200) != 0) {
      sVar19 = sVar19 + 6;
    }
    if ((uVar3 & 0x400) != 0) {
      sVar19 = sVar19 + 1;
    }
    if ((int)(uVar15 << 0x14) < 0) {
      sVar19 = sVar19 + 2;
    }
    if ((int)(uVar15 << 0x13) < 0) {
      __src = (void *)r_emi_get_mem_addr_by_offset(sVar2 + sVar19);
      memcpy(auStack_44,__src,3);
      iVar8 = r_emi_get_mem_addr_by_offset(0x1000);
      if ((*(ushort *)(iVar8 + iVar17 + 2) >> 9 & 1) == 0) {
        if (*(byte *)(iVar5 + 0x54) < 7) {
          iVar8 = r_lld_calc_aux_rx(iVar5 + 0x24,(uint)bVar1,auStack_44[0]);
          uVar13 = 0x101;
          if (iVar8 != 0) goto _L145;
        }
        uVar13 = 2;
      }
      else {
        uVar13 = 0x201;
      }
_L145:
      *(undefined2 *)(iVar5 + 0x62) = uVar13;
      sVar19 = sVar19 + 3;
    }
    else {
      *(undefined2 *)(iVar5 + 0x62) = 0;
    }
    if ((int)(uVar15 << 0x12) < 0) {
      sVar19 = sVar19 + 0x12;
    }
    if ((int)(uVar15 << 0x11) < 0) {
      puVar11 = (undefined1 *)r_emi_get_mem_addr_by_offset(sVar2 + sVar19);
      sVar19 = sVar19 + 1;
      puVar10[0xb] = *puVar11;
    }
    if (param_2 == 0) {
      puVar10[0x19] = 0;
      puVar10[0x1a] = 0;
    }
    else {
      puVar10[0x19] = ((char)uVar16 + -1) - (char)sVar19;
      puVar10[0x1a] = (char)sVar19;
    }
  }
  pcVar4 = _rwip_rf;
  iVar8 = r_emi_get_mem_addr_by_offset(0x1000);
  uVar7 = (*pcVar4)(*(ushort *)(iVar17 + 6 + iVar8) & 0xff);
  puVar10[0xc] = uVar7;
  uVar14 = *(short *)(iVar5 + 0x52) + uVar6;
  *(ushort *)(iVar5 + 0x52) = uVar14;
  if (0x672 < uVar14) {
    uVar6 = (uVar6 + 0x72) - uVar14 & 0xff;
    *(undefined2 *)(iVar5 + 0x62) = 2;
  }
  puVar10[0xe] = (char)uVar6;
  puVar10[0xd] = *(undefined1 *)(iVar5 + 0x62);
  if ((uVar6 != 0) || (puVar10[0x19] != '\0')) {
    *(short *)(puVar10 + 0x10) = sVar2;
    uVar12 = r_emi_get_mem_addr_by_offset(sVar2);
    *(undefined4 *)(puVar10 + 0x14) = uVar12;
    puVar10[0x18] = cVar18;
    bVar1 = *(byte *)(_p_lld_env + 0xd8);
    iVar8 = r_emi_get_mem_addr_by_offset(0x1000);
    *(undefined2 *)(iVar8 + (uint)bVar1 * 0x14 + 0x12) = 0;
  }
  if (puVar10[0xd] == '\0') {
    uVar12 = 3;
  }
  else {
    uVar12 = 2;
    if (puVar10[0xd] != '\x02') goto _L117;
  }
  r_lld_sync_scan_dynamic_pti_process(iVar5,uVar12);
_L117:
  r_ke_msg_send(puVar10);
  return;
}

