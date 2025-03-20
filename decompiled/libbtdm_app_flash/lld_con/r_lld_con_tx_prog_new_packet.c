/*
 * Last changed at upstream commit daab5dbba958a13041bd496e4a6ed506c9284a06
 * https://github.com/espressif/esp32c3-bt-lib/commit/daab5dbba958a13041bd496e4a6ed506c9284a06
 * Upstream date: 2025-03-20 20:43:40 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(86a4da5c)
 * Source: libbtdm_app_flash -> lld_con.o -> r_lld_con_tx_prog_new_packet
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_con_tx_prog_new_packet(uint param_1,uint param_2)

{
  char cVar1;
  byte bVar2;
  ushort uVar3;
  ushort uVar4;
  int *piVar5;
  uint uVar6;
  int iVar7;
  ushort *puVar8;
  byte *pbVar9;
  undefined1 *puVar10;
  int *piVar11;
  uint uVar12;
  int iVar13;
  ushort uVar14;
  int iVar15;
  byte bVar16;
  uint uVar17;
  byte bVar18;
  int iVar19;
  char cVar20;
  int iVar21;
  int iVar22;
  int *piStack_64;
  
  iVar19 = *(int *)(&lld_con_env + param_1 * 4);
  iVar22 = *(int *)(iVar19 + 0x24);
  piVar5 = *(int **)(iVar19 + 0x30);
  piStack_64 = (int *)0x0;
  if ((((*(ushort *)(iVar19 + 0x84) & 0x10) != 0) && (piStack_64 = piVar5, piVar5 != (int *)0x0)) &&
     (piStack_64 = (int *)0x1, *(short *)(iVar19 + 0x82) == 0)) {
    piStack_64 = (int *)(uint)(*piVar5 != 0);
  }
  bVar18 = *(byte *)(iVar19 + 0x92);
  iVar15 = (param_1 + 0x18) * 2;
  do {
    if (1 < bVar18) {
      return;
    }
    if (iVar22 == 0) {
      if (piStack_64 == (int *)0x0) {
        return;
      }
_L444:
      if ((*(short *)(iVar19 + 0x82) == 0) && (piVar11 = (int *)*piVar5, piVar11 != (int *)0x0)) {
        uVar3 = *(ushort *)((int)piVar11 + 6);
        *(int **)(iVar19 + 0x30) = piVar11;
        *(ushort *)(iVar19 + 0x82) = uVar3 & 0x3ff;
        piVar5 = piVar11;
      }
      uVar3 = *(ushort *)((int)piVar5 + 6);
      uVar4 = *(ushort *)(iVar19 + 0x82);
      uVar17 = (uint)uVar4;
      uVar6 = (*(ushort *)(piVar5 + 1) - uVar17) + (uVar3 & 0x3ff) & 0xffff;
      uVar14 = 2;
      if (((int)(uint)uVar3 >> 0xc & 3U) == 1) {
        uVar14 = 1;
      }
      uVar12 = (uint)*(byte *)(iVar19 + 0x8c);
      if (uVar17 < *(byte *)(iVar19 + 0x8c)) {
        uVar12 = uVar17;
      }
      *(ushort *)((int)piVar5 + 6) = uVar3 & 0xcfff | 0x1000;
      *(ushort *)(iVar19 + 0x82) = uVar4 - (short)uVar12;
    }
    else {
      if (((param_2 == 2) && (piStack_64 != (int *)0x0)) &&
         ((bVar18 != 1 && (DAT_0001608e != '\0')))) goto _L444;
      uVar12 = (uint)*(byte *)(iVar22 + 6);
      uVar6 = (uint)*(ushort *)(iVar22 + 4);
      uVar14 = 3;
      *(undefined4 *)(iVar19 + 0x24) = 0;
      iVar22 = 0;
    }
    uVar3 = *(ushort *)(iVar19 + 0x84);
    cVar20 = *(char *)(iVar19 + 0x8e) * '\t';
    cVar1 = *(char *)(iVar19 + 0x91);
    bVar16 = cVar20 + cVar1;
    uVar17 = (uint)bVar16;
    piStack_64 = (int *)0x0;
    if ((((uVar3 & 0x10) != 0) && (piStack_64 = piVar5, piVar5 != (int *)0x0)) &&
       (piStack_64 = (int *)0x1, *(short *)(iVar19 + 0x82) == 0)) {
      piStack_64 = (int *)(uint)(*piVar5 != 0);
    }
    if ((uVar3 & 0x40) != 0) {
      uVar12 = uVar12 + 4 & 0xffff;
    }
    if ((int)((uint)uVar3 << 0x12) < 0) {
      piVar11 = (int *)0x0;
    }
    else {
      piVar11 = piStack_64;
      if (piStack_64 == (int *)0x0) {
        piVar11 = (int *)(uVar3 & 1);
      }
    }
    iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
    iVar13 = uVar17 * 0xe;
    *(ushort *)(iVar7 + iVar13 + 2) =
         (ushort)((uVar12 & 0xff) << 8) | uVar14 | (ushort)((int)piVar11 << 4);
    iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
    *(short *)(iVar7 + iVar13 + 4) = (short)uVar6;
    if (-1 < (int)((uint)*(ushort *)(iVar19 + 0x84) << 0x12)) {
      iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
      iVar21 = (uint)(byte)((cVar1 + 1U & 1) + cVar20) * 0xe;
      if (-1 < *(short *)(iVar7 + iVar21)) {
        iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
        iVar21 = iVar21 + 2;
        uVar3 = *(ushort *)(iVar7 + iVar21);
        iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
        *(ushort *)(iVar7 + iVar21) = uVar3 & 0xffef | 0x10;
      }
    }
    if (uVar14 == 3) {
      if (param_2 == 2) {
        bVar2 = *(byte *)(iVar19 + 0x90);
        *(undefined1 *)(&lld_con_cntl_pkt_info + param_1) = 1;
        *(byte *)((int)&lld_con_cntl_pkt_info + param_1 * 4 + 1) = bVar16;
        if (uVar17 == (uint)bVar2 + param_1 * 9) {
          *(undefined1 *)((int)&lld_con_cntl_pkt_info + param_1 * 4 + 2) = 1;
        }
      }
      else if ((param_2 < 2) || (param_2 == 0x18)) {
        if (param_2 == 0) {
          (&DAT_00015031)[iVar15] = 1;
          iVar7 = 10;
        }
        else if (param_2 == 1) {
          (&DAT_00015031)[iVar15] = 2;
          iVar7 = 6;
        }
        else if (param_2 == 0x18) {
          (&DAT_00015031)[iVar15] = 3;
          iVar7 = 3;
        }
        else {
          r_assert_param(param_1,param_2,"lld_con.c",0x4f6);
          iVar7 = 0;
        }
        uVar12 = uVar6 + iVar7 & 0xffff;
        (&DAT_00015030)[iVar15] = bVar16;
        puVar8 = (ushort *)r_emi_get_mem_addr_by_offset(uVar12);
        uVar4 = *puVar8;
        uVar3 = *(ushort *)(iVar19 + 0x44);
        if (((uint)uVar3 == (uint)uVar4) &&
           (pbVar9 = (byte *)r_emi_get_mem_addr_by_offset(uVar6), *pbVar9 == param_2)) {
          uVar6 = (uint)*(ushort *)(iVar19 + 0x7c) + (uint)*(ushort *)(iVar19 + 0x7e) + 9 +
                  (uint)*(ushort *)(iVar19 + 0x72);
          iVar7 = uVar6 * 0x10000;
          uVar6 = uVar6 & 0xffff;
          if (((uVar6 + 1) - (uint)uVar3 & 0xffff) < 0x7fff) {
            puVar10 = (undefined1 *)r_emi_get_mem_addr_by_offset(uVar12);
            *puVar10 = (char)((uint)iVar7 >> 0x10);
            puVar10[1] = (char)(uVar6 >> 8);
            *(short *)(iVar19 + 0x44) = (short)((uint)iVar7 >> 0x10);
          }
        }
        else {
          if (0 < _g_bt_plf_log_level) {
            uVar3 = *(ushort *)(iVar19 + 0x7e);
            uVar14 = *(ushort *)(iVar19 + 0x7c);
            puVar10 = (undefined1 *)r_emi_get_mem_addr_by_offset(uVar6);
            ets_printf("llcp prog: %u %u %u %u %u\n",(uint)uVar14 + (uint)uVar3,*puVar10,(uint)uVar4
                       ,*(undefined1 *)(iVar19 + 0x46),*(undefined2 *)(iVar19 + 0x44));
          }
          *(undefined2 *)(&DAT_00015030 + iVar15) = 0;
        }
      }
    }
    iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
    uVar3 = *(ushort *)(iVar7 + iVar13);
    iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
    *(ushort *)(iVar7 + iVar13) = uVar3 & 0x7fff;
    *(byte *)(iVar19 + 0x91) = *(char *)(iVar19 + 0x91) + 1U & 1;
    r_lld_con_tx_prog_new_packet_coex(iVar19);
    *(char *)(iVar19 + 0x92) = *(char *)(iVar19 + 0x92) + '\x01';
    iVar7 = r_sdk_config_get_opts_ext();
    if (((*(uint *)(iVar7 + 0x28) & 0x20) != 0) &&
       (iVar7 = r_sdk_config_get_opts_ext(), *(byte *)(iVar7 + 0x2c) < 3)) {
      iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
      r_ble_log_internal_x2
                (0x40e30013,uVar17 << 0x10 | param_2 << 8 | param_1,
                 *(undefined2 *)(iVar7 + iVar13 + 2));
    }
    bVar18 = bVar18 + 1;
  } while( true );
}

