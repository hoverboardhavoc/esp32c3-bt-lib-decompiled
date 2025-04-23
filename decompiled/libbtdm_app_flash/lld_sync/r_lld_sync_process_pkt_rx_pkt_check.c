/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
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
  ushort uVar1;
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
  char cVar11;
  uint uVar12;
  byte bVar13;
  ushort uVar14;
  ushort uVar15;
  ushort uVar16;
  int iVar17;
  uint uVar18;
  uint uVar19;
  ushort uVar20;
  uint uVar21;
  char cStack_5c;
  undefined4 auStack_44 [4];
  
  iVar4 = *(int *)(&lld_sync_env + param_1 * 4);
  uVar18 = (uint)*(byte *)(_p_lld_env + 0xd8);
  iVar17 = uVar18 * 0x14;
  iVar6 = r_emi_get_mem_addr_by_offset(0x1000);
  uVar15 = *(ushort *)(iVar6 + iVar17 + 2);
  iVar6 = r_emi_get_mem_addr_by_offset(0x1000);
  uVar1 = *(ushort *)(iVar17 + 0x12 + iVar6);
  uVar19 = (uint)uVar1;
  if ((uVar15 & 0x603d) != 0) {
    iVar4 = r_sdk_config_get_opts_ext();
    if ((*(uint *)(iVar4 + 0x28) & 0x80) != 0) {
      iVar4 = r_sdk_config_get_opts_ext();
      if (*(byte *)(iVar4 + 0x2c) < 2) {
        r_ble_log_internal_x1(0x20a2000e,uVar18 << 8 | param_1 | (uint)uVar15 << 0x10);
        return;
      }
    }
    return;
  }
  iVar6 = r_sdk_config_get_opts_ext();
  if ((*(uint *)(iVar6 + 0x28) & 0x80) != 0) {
    iVar6 = r_sdk_config_get_opts_ext();
    if (*(byte *)(iVar6 + 0x2c) < 2) {
      r_ble_log_internal_x1(0x20a2000d,uVar18 << 8 | param_1);
    }
  }
  iVar7 = r_sdk_config_get_opts_ext();
  iVar6 = iVar17 + 4;
  if ((*(uint *)(iVar7 + 0x28) & 0x80) != 0) {
    iVar7 = r_sdk_config_get_opts_ext();
    if (*(byte *)(iVar7 + 0x2c) < 2) {
      iVar7 = r_emi_get_mem_addr_by_offset(0x1000);
      uVar15 = *(ushort *)(iVar7 + iVar6);
      uVar8 = r_emi_get_mem_addr_by_offset(uVar19);
      r_ble_log_internal_hex(0x20a2000f,uVar15 >> 8,uVar8);
    }
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
  uVar15 = *(ushort *)(iVar7 + iVar17 + 0x10);
  iVar7 = r_emi_get_mem_addr_by_offset(0x1000);
  uVar16 = uVar15 & 0x3f;
  if (*(ushort *)(iVar7 + iVar6) >> 8 <= uVar16) {
    r_assert_err(0,0x10000,0x1de);
  }
  cStack_5c = '\0';
  if ((uVar15 & 0x3f) != 0) {
    cStack_5c = (char)uVar16 + -1;
  }
  iVar7 = r_emi_get_mem_addr_by_offset(0x1000);
  uVar14 = (*(ushort *)(iVar7 + iVar6) >> 8) - uVar16 & 0xff;
  puVar9 = (undefined1 *)r_ke_msg_alloc(0x204,0,0xff,0x1c);
  *puVar9 = (char)param_1;
  uVar12 = *(uint *)(iVar4 + 0x40);
  cVar11 = *(char *)(iVar4 + 0x57);
  *(undefined2 *)(puVar9 + 8) = *(undefined2 *)(iVar4 + 0x4a);
  uVar20 = uVar14 - 1 & 0xff;
  uVar21 = uVar12 >> 1;
  if (cVar11 == '\0') {
    *(undefined1 *)(iVar4 + 0x57) = 1;
    puVar9[1] = *(undefined1 *)(iVar4 + 0x58);
    uVar5 = *(undefined1 *)(iVar4 + 0x59);
    *(short *)(puVar9 + 4) = (short)(uVar12 >> 2);
    puVar9[2] = uVar5;
    uVar12 = *(uint *)(iVar4 + 0x44);
    if (uVar21 == 0) {
      r_assert_err(0,0x10000,0x94);
    }
    *(short *)(puVar9 + 6) = (short)((uVar12 >> 1) % uVar21);
    puVar9[10] = *(undefined1 *)(iVar4 + 0x5a);
    iVar6 = r_sdk_config_get_opts_ext();
    if ((*(uint *)(iVar6 + 0x28) & 0x80) != 0) {
      iVar6 = r_sdk_config_get_opts_ext();
      if (*(byte *)(iVar6 + 0x2c) < 3) {
        r_ble_log_internal_x2
                  (0x40020003,param_2 << 0x10 | uVar18 << 8 | param_1,*(undefined4 *)(iVar4 + 0x44))
        ;
      }
    }
  }
  else {
    if (param_2 != 0) {
      uVar12 = *(uint *)(iVar4 + 0x44);
      if (uVar21 == 0) {
        r_assert_err(0,0x10000,0x94);
      }
      uVar21 = (uVar12 >> 1) % uVar21;
    }
    *(short *)(puVar9 + 6) = (short)uVar21;
  }
  iVar6 = r_emi_get_mem_addr_by_offset(0x1000);
  uVar2 = *(ushort *)(iVar6 + iVar17 + 0x10);
  uVar21 = (uint)uVar2;
  if ((uVar15 & 0x3f) == 0) {
    *(undefined2 *)(iVar4 + 0x62) = 0;
  }
  else {
    uVar12 = (int)(uVar21 << 0x17) >> 0x1f & 6;
    if ((uVar2 & 0x200) != 0) {
      uVar12 = uVar12 + 6;
    }
    iVar6 = uVar12 + ((uVar2 & 0x400) != 0);
    if ((int)(uVar21 << 0x14) < 0) {
      iVar6 = iVar6 + 2;
    }
    if ((int)(uVar21 << 0x13) < 0) {
      __src = (void *)r_emi_get_mem_addr_by_offset(uVar19 + iVar6 & 0xffff);
      memcpy(auStack_44,__src,3);
      iVar7 = r_emi_get_mem_addr_by_offset(0x1000);
      uVar15 = *(ushort *)(iVar7 + iVar17 + 2);
      uVar5 = 2;
      bVar13 = (byte)(uVar15 >> 9) & 1;
      if ((uVar15 >> 9 & 1) == 0) {
        if ((*(byte *)(iVar4 + 0x54) < 7) &&
           (iVar7 = r_lld_calc_aux_rx(iVar4 + 0x24,uVar18,auStack_44[0]), iVar7 != 0)) {
          bVar13 = 1;
          uVar5 = 1;
        }
        else {
          uVar5 = 0;
          bVar13 = 2;
        }
      }
      *(undefined1 *)(iVar4 + 99) = uVar5;
      *(byte *)(iVar4 + 0x62) = bVar13;
      iVar6 = iVar6 + 3;
    }
    else {
      *(undefined2 *)(iVar4 + 0x62) = 0;
    }
    if ((int)(uVar21 << 0x12) < 0) {
      iVar6 = iVar6 + 0x12;
    }
    if ((int)(uVar21 << 0x11) < 0) {
      puVar10 = (undefined1 *)r_emi_get_mem_addr_by_offset(uVar19 + iVar6 & 0xffff);
      iVar6 = iVar6 + 1;
      puVar9[0xb] = *puVar10;
    }
    if (param_2 == 0) {
      puVar9[0x19] = 0;
      puVar9[0x1a] = 0;
    }
    else {
      puVar9[0x19] = ((char)uVar16 + -1) - (char)iVar6;
      puVar9[0x1a] = (char)iVar6;
    }
  }
  pcVar3 = _r_ble_log_internal_x3;
  iVar6 = r_emi_get_mem_addr_by_offset(0x1000);
  uVar5 = (*pcVar3)(*(ushort *)(iVar17 + 6 + iVar6) & 0xff);
  puVar9[0xc] = uVar5;
  uVar15 = *(short *)(iVar4 + 0x52) + uVar20;
  *(ushort *)(iVar4 + 0x52) = uVar15;
  if (0x672 < uVar15) {
    uVar20 = (uVar14 + 0x71) - uVar15 & 0xff;
    *(undefined2 *)(iVar4 + 0x62) = 2;
  }
  puVar9[0xe] = (char)uVar20;
  puVar9[0xd] = *(undefined1 *)(iVar4 + 0x62);
  if ((uVar20 != 0) || (puVar9[0x19] != '\0')) {
    *(ushort *)(puVar9 + 0x10) = uVar1;
    uVar8 = r_emi_get_mem_addr_by_offset(uVar19);
    *(undefined4 *)(puVar9 + 0x14) = uVar8;
    puVar9[0x18] = cStack_5c;
    bVar13 = *(byte *)(_p_lld_env + 0xd8);
    iVar6 = r_emi_get_mem_addr_by_offset(0x1000);
    *(undefined2 *)((uint)bVar13 * 0x14 + 0x12 + iVar6) = 0;
  }
  cVar11 = puVar9[0xd];
  if (cVar11 == '\0') {
    cVar11 = '\x03';
  }
  else if (cVar11 != '\x02') goto _L126;
  r_lld_sync_scan_dynamic_pti_process(iVar4,cVar11);
_L126:
  r_ke_msg_send(puVar9);
  return;
}

