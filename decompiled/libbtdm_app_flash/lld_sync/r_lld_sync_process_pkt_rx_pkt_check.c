/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
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
  int iVar4;
  undefined1 uVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  undefined1 *puVar9;
  void *__src;
  undefined1 *puVar10;
  uint uVar11;
  byte bVar12;
  ushort uVar13;
  ushort uVar14;
  uint uVar15;
  ushort uVar16;
  int iVar17;
  uint uVar18;
  short sVar19;
  ushort uVar20;
  char local_60;
  undefined4 auStack_44 [4];
  
  iVar4 = *(int *)(&lld_sync_env + param_1 * 4);
  uVar18 = (uint)*(byte *)(_p_lld_env + 0xd8);
  iVar17 = uVar18 * 0x14;
  iVar6 = r_emi_get_mem_addr_by_offset(0x1000);
  uVar14 = *(ushort *)(iVar6 + iVar17 + 2);
  iVar6 = r_emi_get_mem_addr_by_offset(0x1000);
  sVar1 = *(short *)(iVar17 + 0x12 + iVar6);
  if ((uVar14 & 0x603d) != 0) {
    iVar4 = r_sdk_config_get_opts_ext();
    if (((*(uint *)(iVar4 + 0x28) & 0x80) != 0) &&
       (iVar4 = r_sdk_config_get_opts_ext(), *(byte *)(iVar4 + 0x2c) < 2)) {
      r_ble_log_internal_x1(0x20a2000e,uVar18 << 8 | param_1 | (uint)uVar14 << 0x10);
      return;
    }
    return;
  }
  iVar6 = r_sdk_config_get_opts_ext();
  if (((*(uint *)(iVar6 + 0x28) & 0x80) != 0) &&
     (iVar6 = r_sdk_config_get_opts_ext(), *(byte *)(iVar6 + 0x2c) < 2)) {
    r_ble_log_internal_x1(0x20a2000d,uVar18 << 8 | param_1);
  }
  iVar7 = r_sdk_config_get_opts_ext();
  iVar6 = iVar17 + 4;
  if (((*(uint *)(iVar7 + 0x28) & 0x80) != 0) &&
     (iVar7 = r_sdk_config_get_opts_ext(), *(byte *)(iVar7 + 0x2c) < 2)) {
    iVar7 = r_emi_get_mem_addr_by_offset(0x1000);
    uVar14 = *(ushort *)(iVar7 + iVar6);
    uVar8 = r_emi_get_mem_addr_by_offset(sVar1);
    r_ble_log_internal_hex(0x20a2000f,uVar14 >> 8,uVar8);
  }
  iVar7 = r_emi_get_mem_addr_by_offset(0x1000);
  if ((*(ushort *)(iVar7 + iVar6) & 0xf) != 7) {
    r_assert_err(0,0x10000,0x1cf);
  }
  *(undefined4 *)(iVar4 + 0x3c) = *(undefined4 *)(iVar4 + 0x44);
  *(char *)(iVar4 + 100) = *(char *)(iVar4 + 100) + '\x01';
  if (param_2 == 0) {
    *(char *)(iVar4 + 0x54) = *(char *)(iVar4 + 0x54) + '\x01';
  }
  iVar7 = r_emi_get_mem_addr_by_offset(0x1000);
  uVar14 = *(ushort *)(iVar7 + iVar17 + 0x10);
  iVar7 = r_emi_get_mem_addr_by_offset(0x1000);
  uVar16 = uVar14 & 0x3f;
  if (*(ushort *)(iVar7 + iVar6) >> 8 <= uVar16) {
    r_assert_err(0,0x10000,0x1de);
  }
  local_60 = '\0';
  if ((uVar14 & 0x3f) != 0) {
    local_60 = (char)uVar16 + -1;
  }
  iVar7 = r_emi_get_mem_addr_by_offset(0x1000);
  uVar13 = (*(ushort *)(iVar6 + iVar7) >> 8) - uVar16 & 0xff;
  puVar9 = (undefined1 *)r_ke_msg_alloc(0x204,0,0xff,0x1c);
  *puVar9 = (char)param_1;
  uVar20 = uVar13 - 1 & 0xff;
  *(undefined2 *)(puVar9 + 8) = *(undefined2 *)(iVar4 + 0x4a);
  if (*(char *)(iVar4 + 0x57) == '\0') {
    *(undefined1 *)(iVar4 + 0x57) = 1;
    puVar9[1] = *(undefined1 *)(iVar4 + 0x58);
    puVar9[2] = *(undefined1 *)(iVar4 + 0x59);
    uVar11 = *(uint *)(iVar4 + 0x40);
    *(short *)(puVar9 + 4) = (short)(uVar11 >> 2);
    uVar15 = *(uint *)(iVar4 + 0x44);
    uVar11 = uVar11 >> 1;
    if (uVar11 == 0) {
      r_assert_err(0,0x10000,0x94);
    }
    *(short *)(puVar9 + 6) = (short)((uVar15 >> 1) % uVar11);
    puVar9[10] = *(undefined1 *)(iVar4 + 0x5a);
    iVar6 = r_sdk_config_get_opts_ext();
    if (((*(uint *)(iVar6 + 0x28) & 0x80) != 0) &&
       (iVar6 = r_sdk_config_get_opts_ext(), *(byte *)(iVar6 + 0x2c) < 3)) {
      r_ble_log_internal_x2
                (0x40020003,param_2 << 0x10 | uVar18 << 8 | param_1,*(undefined4 *)(iVar4 + 0x44));
    }
  }
  else {
    uVar11 = *(uint *)(iVar4 + 0x40) >> 1;
    if (param_2 != 0) {
      uVar15 = *(uint *)(iVar4 + 0x44);
      if (uVar11 == 0) {
        r_assert_err(0,0x10000,0x94);
      }
      uVar11 = (uVar15 >> 1) % uVar11;
    }
    *(short *)(puVar9 + 6) = (short)uVar11;
  }
  iVar6 = r_emi_get_mem_addr_by_offset(0x1000);
  uVar2 = *(ushort *)(iVar6 + iVar17 + 0x10);
  if ((uVar14 & 0x3f) == 0) {
    *(undefined2 *)(iVar4 + 0x62) = 0;
  }
  else {
    sVar19 = 0;
    if ((uVar2 & 0x100) != 0) {
      sVar19 = 6;
    }
    if ((uVar2 & 0x200) != 0) {
      sVar19 = sVar19 + 6;
    }
    if ((uVar2 & 0x400) != 0) {
      sVar19 = sVar19 + 1;
    }
    if ((uVar2 >> 0xb & 1) != 0) {
      sVar19 = sVar19 + 2;
    }
    if ((uVar2 & 0x1000) == 0) {
      *(undefined2 *)(iVar4 + 0x62) = 0;
    }
    else {
      __src = (void *)r_emi_get_mem_addr_by_offset(sVar1 + sVar19);
      memcpy(auStack_44,__src,3);
      iVar6 = r_emi_get_mem_addr_by_offset(0x1000);
      uVar14 = *(ushort *)(iVar6 + iVar17 + 2);
      uVar5 = 2;
      bVar12 = (byte)(uVar14 >> 9) & 1;
      if ((uVar14 >> 9 & 1) == 0) {
        if ((*(byte *)(iVar4 + 0x54) < 7) &&
           (iVar6 = r_lld_calc_aux_rx(iVar4 + 0x24,uVar18,auStack_44[0]), iVar6 != 0)) {
          uVar5 = 1;
          bVar12 = 1;
        }
        else {
          uVar5 = 0;
          bVar12 = 2;
        }
      }
      *(undefined1 *)(iVar4 + 99) = uVar5;
      *(byte *)(iVar4 + 0x62) = bVar12;
      sVar19 = sVar19 + 3;
    }
    if ((uVar2 & 0x2000) != 0) {
      sVar19 = sVar19 + 0x12;
    }
    if ((uVar2 & 0x4000) != 0) {
      puVar10 = (undefined1 *)r_emi_get_mem_addr_by_offset(sVar1 + sVar19);
      sVar19 = sVar19 + 1;
      puVar9[0xb] = *puVar10;
    }
    if (param_2 == 0) {
      puVar9[0x19] = 0;
      puVar9[0x1a] = 0;
    }
    else {
      puVar9[0x19] = ((char)uVar16 + -1) - (char)sVar19;
      puVar9[0x1a] = (char)sVar19;
    }
  }
  pcVar3 = _r_lld_read_clock;
  iVar6 = r_emi_get_mem_addr_by_offset(0x1000);
  uVar5 = (*pcVar3)(*(ushort *)(iVar17 + 6 + iVar6) & 0xff);
  puVar9[0xc] = uVar5;
  uVar14 = *(short *)(iVar4 + 0x52) + uVar20;
  *(ushort *)(iVar4 + 0x52) = uVar14;
  if (0x672 < uVar14) {
    uVar20 = (uVar13 + 0x71) - uVar14 & 0xff;
    *(undefined2 *)(iVar4 + 0x62) = 2;
  }
  puVar9[0xe] = (char)uVar20;
  puVar9[0xd] = *(undefined1 *)(iVar4 + 0x62);
  if ((uVar20 != 0) || (puVar9[0x19] != '\0')) {
    *(short *)(puVar9 + 0x10) = sVar1;
    uVar8 = r_emi_get_mem_addr_by_offset(sVar1);
    *(undefined4 *)(puVar9 + 0x14) = uVar8;
    puVar9[0x18] = local_60;
    bVar12 = *(byte *)(_p_lld_env + 0xd8);
    iVar6 = r_emi_get_mem_addr_by_offset(0x1000);
    *(undefined2 *)((uint)bVar12 * 0x14 + 0x12 + iVar6) = 0;
  }
  if (puVar9[0xd] == '\0') {
    uVar8 = 3;
  }
  else {
    uVar8 = 2;
    if (puVar9[0xd] != '\x02') goto _L131;
  }
  r_lld_sync_scan_dynamic_pti_process(iVar4,uVar8);
_L131:
  r_ke_msg_send(puVar9);
  return;
}

