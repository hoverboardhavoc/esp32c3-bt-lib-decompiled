/*
 * Last changed at upstream commit daab5dbba958a13041bd496e4a6ed506c9284a06
 * https://github.com/espressif/esp32c3-bt-lib/commit/daab5dbba958a13041bd496e4a6ed506c9284a06
 * Upstream date: 2025-03-20 20:43:40 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(86a4da5c)
 * Source: libbtdm_app -> llm_adv.o -> lld_adv_end_ind_handler_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 lld_adv_end_ind_handler_hack(byte *param_1)

{
  char cVar1;
  byte bVar2;
  ushort uVar3;
  byte bVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  undefined1 *puVar8;
  byte *pbVar9;
  int iVar10;
  undefined4 *puVar11;
  int iVar12;
  undefined1 uVar13;
  code *pcVar14;
  undefined1 *puVar15;
  int iVar16;
  uint uVar17;
  byte bVar18;
  uint uVar19;
  byte bStack_77;
  ushort uStack_76;
  ushort uStack_74;
  undefined2 uStack_72;
  undefined2 uStack_70;
  undefined2 uStack_6e;
  undefined2 uStack_6c;
  undefined2 uStack_6a;
  undefined4 uStack_68;
  undefined2 uStack_64;
  byte bStack_62;
  byte bStack_61;
  undefined4 uStack_60;
  uint uStack_5c;
  undefined4 uStack_58;
  undefined2 uStack_54;
  undefined2 uStack_52;
  ushort uStack_50;
  undefined2 uStack_4e;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  byte bStack_44;
  undefined1 uStack_43;
  byte bStack_42;
  byte bStack_41;
  
  uVar17 = (uint)*param_1;
  iVar16 = uVar17 * 0x44;
  bVar18 = param_1[0x35];
  puVar11 = (undefined4 *)(*(int *)(_p_llm_env + 8) + iVar16);
  bStack_77 = *(byte *)((int)puVar11 + 0x3e);
  puVar15 = (undefined1 *)*puVar11;
  if (*(char *)(puVar11 + 0x10) == '\x03') {
    if (*(char *)(_p_llm_env + 0xd7) == '\x01') {
      pcVar14 = *(code **)(_r_ip_funcs_p + 0x4b8);
      uVar5 = 0x200a;
_L739:
      (*pcVar14)(uVar5,0,pcVar14);
    }
    else {
      if (*(char *)(_p_llm_env + 0xd6) == '\0') {
        (**(code **)(_r_plf_funcs_p + 8))(0,"llm_adv.c",0xa4f,*(code **)(_r_plf_funcs_p + 8));
      }
      cVar1 = *(char *)(_p_llm_env + 0xd6);
      *(char *)(_p_llm_env + 0xd6) = cVar1 + -1;
      if (cVar1 == '\x01') {
        pcVar14 = *(code **)(_r_ip_funcs_p + 0x4b8);
        uVar5 = 0x2039;
        goto _L739;
      }
    }
    *(undefined1 *)(*(int *)(_p_llm_env + 8) + iVar16 + 0x40) = 1;
_L653:
    if ((*(ushort *)(puVar15 + 2) & 1) != 0) {
      iVar10 = *(int *)(_p_llm_env + 8) + iVar16;
      if ((*(char *)(iVar10 + 0x40) != '\x02') ||
         ((uint)*(byte *)(iVar10 + 0x3e) != (uint)bStack_77)) {
        *(undefined1 *)(*(int *)(_p_llm_env + 8) + (uint)bStack_77 * 0x44 + 0x40) = 0;
      }
    }
    bVar18 = 0;
    if (param_1[1] != 0x3c) goto _L696;
  }
  else {
    if (bVar18 == 0) {
      if ((param_1[1] == 0x3c) || (param_1[1] == 0x43)) {
        *(undefined1 *)(puVar11 + 0x10) = 1;
      }
      goto _L653;
    }
    pbVar9 = param_1 + 0x15;
    iVar10 = (**(code **)(_r_ip_funcs_p + 0x4d8))
                       (pbVar9,param_1[0x37],*(code **)(_r_ip_funcs_p + 0x4d8));
    if (iVar10 != 0) {
      memset(&uStack_68,0,0x28);
      if ((*(ushort *)(puVar15 + 2) & 0xc) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"llm_adv.c",0xa6c,*(code **)(_r_plf_funcs_p + 8));
      }
      uStack_50 = *(ushort *)(puVar15 + 2);
      uVar3 = uStack_50 & 4;
      uStack_5c = (uint)(byte)puVar15[9] << 0x10 | (uint)(byte)puVar15[8] << 8 |
                  (uint)(byte)puVar15[7];
      uStack_4c = CONCAT13(puVar15[0xc],
                           CONCAT12(puVar15[0xb],CONCAT11(puVar15[10],(undefined1)uStack_4c)));
      memcpy(&bStack_62,puVar15 + 0xd,6);
      uVar13 = 0;
      if (uVar3 == 0) {
        uVar13 = puVar15[0x13];
      }
      bStack_44 = puVar15[0x15];
      uStack_48 = CONCAT13(puVar15[0x16],CONCAT12(bStack_44,CONCAT11(puVar15[0x14],uVar13)));
      uStack_43 = puVar15[0x18];
      bStack_42 = puVar15[0x19];
      iVar10 = *(int *)(_p_llm_env + 8) + iVar16;
      uStack_68 = *(undefined4 *)(iVar10 + 4);
      uStack_64 = *(undefined2 *)(iVar10 + 8);
      uStack_54 = *(undefined2 *)(iVar10 + 0x2a);
      uStack_52 = *(undefined2 *)(iVar10 + 0x34);
      uStack_4c = uStack_4c & 0xffffff00;
      uStack_58 = CONCAT22(*(undefined2 *)(iVar10 + 0x32),*(undefined2 *)(iVar10 + 0x28));
      bStack_41 = *(byte *)(_p_llm_env + 0xc6);
      uStack_4e = 0;
      iVar10 = (**(code **)(_r_ip_funcs_p + 0x1e4))
                         (uVar17,&uStack_68,*(code **)(_r_ip_funcs_p + 0x1e4));
      if (iVar10 == 0) {
        *(undefined1 *)(*(int *)(_p_llm_env + 8) + iVar16 + 0x40) = 2;
        if ((_bt_rf_coex_hooks_p != (undefined4 *)0x0) &&
           ((code *)*_bt_rf_coex_hooks_p != (code *)0x0)) {
          uVar5 = 0;
          if ((*(ushort *)(puVar15 + 2) & 0x10) == 0) {
            uVar5 = 2;
          }
          (*(code *)*_bt_rf_coex_hooks_p)(uVar17,uVar5,1);
        }
      }
      else {
        (**(code **)(_r_plf_funcs_p + 8))(0,"llm_adv.c",0xa9a,*(code **)(_r_plf_funcs_p + 8));
      }
      goto _L653;
    }
    uStack_48 = 0;
    uStack_68 = *(undefined4 *)(param_1 + 2);
    uStack_64 = *(undefined2 *)(param_1 + 6);
    bStack_62 = param_1[8];
    bStack_61 = param_1[0x1b];
    uStack_60 = *(undefined4 *)(param_1 + 0x1c);
    uStack_5c = *(uint *)(param_1 + 0x20);
    uStack_58 = *(undefined4 *)(param_1 + 0x24);
    uStack_54 = *(undefined2 *)(param_1 + 0x28);
    uStack_52 = CONCAT11(uStack_52._1_1_,param_1[0x2a]);
    uStack_50 = *(ushort *)(param_1 + 0x2c);
    uStack_4c = *(uint *)(param_1 + 0x30);
    uStack_43 = 1;
    bStack_44 = param_1[0x34];
    bStack_42 = param_1[0x36];
    bStack_41 = ((byte)(*(ushort *)(puVar15 + 2) >> 4) ^ 1) & 1;
    if (bStack_77 == 0xff) {
      (**(code **)(_r_plf_funcs_p + 8))("llm_adv.c",0xb33,*(code **)(_r_plf_funcs_p + 8));
    }
    else {
      if (*(char *)((uint)bStack_77 * 0x44 + *(int *)(_p_llm_env + 8) + 0x40) == '\0') {
        iVar10 = (**(code **)(_r_ip_funcs_p + 0x4ac))(&bStack_77,*(code **)(_r_ip_funcs_p + 0x4ac));
        iVar12 = *(int *)(_p_llm_env + 8);
        if (iVar10 == 0) {
          *(byte *)(iVar12 + iVar16 + 0x3e) = bStack_77;
          *(undefined1 *)((uint)bStack_77 * 0x44 + iVar12 + 0x40) = 4;
        }
        else {
          (**(code **)(_r_plf_funcs_p + 0xc))
                    (uVar17,*(undefined1 *)((uint)bStack_77 * 0x44 + iVar12 + 0x40),"llm_adv.c",
                     0xac6,*(code **)(_r_plf_funcs_p + 0xc));
        }
      }
      (**(code **)(_r_ip_funcs_p + 0x698))
                (bStack_77,&uStack_68,_p_llm_env + 0x9c,*(code **)(_r_ip_funcs_p + 0x698));
      if (*(char *)(*(int *)(_p_llm_env + 8) + (uint)bStack_77 * 0x44 + 0x40) != '\x04') {
        (**(code **)(_r_plf_funcs_p + 0xc))("llm_adv.c",0xacd,*(code **)(_r_plf_funcs_p + 0xc));
      }
      bVar4 = bStack_77;
      iVar10 = _p_llm_env;
      iVar12 = *(int *)(_p_llm_env + 8) + (uint)bStack_77 * 0x44;
      memcpy((void *)(iVar12 + 4),pbVar9,6);
      bVar2 = param_1[0x37];
      *(undefined1 *)(iVar12 + 0x28) = 1;
      *(byte *)(iVar12 + 0x41) = bVar2;
      *(undefined1 *)(iVar12 + 0x40) = 9;
      uVar3 = *(ushort *)(param_1 + 0x1e);
      *(undefined4 *)(iVar12 + 0x14) = 0;
      *(uint *)(iVar12 + 0x10) = (uint)uVar3 << 1;
      *(undefined4 *)(iVar12 + 0x18) = 5;
      *(undefined4 *)(iVar12 + 0x1c) = 5;
      if (*(char *)(iVar10 + 0xd8) == '\0') {
        *(undefined4 *)(iVar12 + 0x24) = 0;
        *(undefined1 *)(iVar12 + 0x22) = 0;
      }
      else {
        uVar5 = *(undefined4 *)(_r_ip_funcs_p + 0x5e0);
        *(undefined1 *)(iVar12 + 0x22) = 1;
        *(undefined4 *)(iVar12 + 0x24) = uVar5;
      }
      iVar10 = _r_plf_funcs_p;
      *(ushort *)(iVar12 + 0x20) = (ushort)bVar4;
      iVar10 = (**(code **)(iVar10 + 0x38))(*(code **)(iVar10 + 0x38));
      if (*(char *)(iVar10 + 0x15) == '\x01') {
        uVar13 = *(undefined1 *)(iVar12 + 0x20);
        uVar19 = *(uint *)(iVar12 + 0x1c);
        uVar6 = (**(code **)(_r_ip_funcs_p + 0x340))(uVar13,*(code **)(_r_ip_funcs_p + 0x340));
        iVar10 = _r_ip_funcs_p;
        uVar7 = uVar6 / 0x4e2;
        if (uVar6 / 0x4e2 < uVar19) {
          uVar7 = uVar19;
        }
        *(uint *)(iVar12 + 0x1c) = uVar7;
        uVar19 = *(uint *)(iVar12 + 0x18);
        uVar6 = (**(code **)(iVar10 + 0x340))(uVar13,*(code **)(iVar10 + 0x340));
        uVar7 = uVar6 / 0x4e2;
        if (uVar6 / 0x4e2 < uVar19) {
          uVar7 = uVar19;
        }
        *(uint *)(iVar12 + 0x18) = uVar7;
      }
      else {
        iVar10 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
        if ((*(char *)(iVar10 + 0x15) == '\x02') &&
           (iVar10 = (**(code **)(_r_ip_funcs_p + 0x344))
                               (*(undefined1 *)(iVar12 + 0x20),&uStack_76,&uStack_74,
                                *(code **)(_r_ip_funcs_p + 0x344)), iVar10 == 0)) {
          *(uint *)(iVar12 + 0x1c) = (uint)uStack_76;
          *(uint *)(iVar12 + 0x18) = (uint)uStack_74;
        }
      }
      if (sdk_cfg_priv_opts != '\0') {
        (**(code **)(_r_ip_funcs_p + 0x6fc))(iVar12 + 0xc,*(code **)(_r_ip_funcs_p + 0x6fc));
      }
      (**(code **)(_r_ip_funcs_p + 0x288))(pbVar9,param_1[0x37],1,*(code **)(_r_ip_funcs_p + 0x288))
      ;
      uVar7 = (**(code **)(_r_ip_funcs_p + 0x4c8))
                        (pbVar9,param_1[0x37],*(code **)(_r_ip_funcs_p + 0x4c8));
      if ((uVar7 < 0xc) && ((*(byte *)(uVar7 * 10 + _p_llm_env + 0x2d) & 2) != 0)) {
        (**(code **)(_r_ip_funcs_p + 0x2c0))(pbVar9,param_1[0x37],*(code **)(_r_ip_funcs_p + 0x2c0))
        ;
      }
      (**(code **)(_r_ip_funcs_p + 0x74))(bStack_77,*(code **)(_r_ip_funcs_p + 0x74));
      *(undefined1 *)(*(int *)(_p_llm_env + 8) + iVar16 + 0x40) = 1;
      if (_bt_rf_coex_hooks_p != (undefined4 *)0x0) {
        if ((code *)*_bt_rf_coex_hooks_p != (code *)0x0) {
          uVar5 = 0;
          if ((*(ushort *)(puVar15 + 2) & 0x10) == 0) {
            uVar5 = 2;
          }
          (*(code *)*_bt_rf_coex_hooks_p)(uVar17,uVar5,0);
          (*(code *)*_bt_rf_coex_hooks_p)(bStack_77,7,1,(code *)*_bt_rf_coex_hooks_p);
        }
        if ((code *)_bt_rf_coex_hooks_p[1] != (code *)0x0) {
          uStack_74 = *(ushort *)(param_1 + 0x1e);
          uStack_72 = *(undefined2 *)(param_1 + 0x20);
          uStack_6e = 0;
          uStack_6c = 0;
          uStack_6a = 0;
          uStack_70 = (undefined2)*(undefined4 *)(*(int *)(_p_llm_env + 8) + iVar16 + 0x1c);
          (*(code *)_bt_rf_coex_hooks_p[1])(bStack_77,7,&uStack_74);
        }
      }
    }
  }
  iVar10 = (**(code **)(_r_ip_funcs_p + 0x4e0))(9,*(code **)(_r_ip_funcs_p + 0x4e0));
  if (iVar10 == 0) {
    puVar8 = (undefined1 *)(**(code **)(_r_modules_funcs_p + 200))(0x1104,0,0x3e,0x14);
    *puVar8 = 1;
    bVar2 = param_1[0x35];
    uVar13 = 0;
    if (bVar2 == 0) {
      uVar13 = 0x3c;
    }
    puVar8[1] = uVar13;
    if (bVar2 != 0) {
      puVar8[4] = 1;
      *(ushort *)(puVar8 + 2) = (ushort)bStack_77;
      if ((param_1[0x37] & 2) == 0) {
        puVar8[5] = param_1[0x37] & 1;
        pbVar9 = param_1 + 0x15;
      }
      else {
        puVar8[5] = 1;
        pbVar9 = param_1 + 0xf;
      }
      memcpy(puVar8 + 6,pbVar9,6);
      *(undefined2 *)(puVar8 + 0xc) = *(undefined2 *)(param_1 + 0x1e);
      *(undefined2 *)(puVar8 + 0xe) = *(undefined2 *)(param_1 + 0x20);
      *(undefined2 *)(puVar8 + 0x10) = *(undefined2 *)(param_1 + 0x22);
      puVar8[0x12] = param_1[0x2a];
    }
  }
  else {
    puVar8 = (undefined1 *)(**(code **)(_r_modules_funcs_p + 200))(0x1104,0,0x3e,0x20);
    *puVar8 = 10;
    bVar2 = param_1[0x35];
    uVar13 = 0;
    if (bVar2 == 0) {
      uVar13 = 0x3c;
    }
    puVar8[1] = uVar13;
    puVar8[4] = 1;
    *(ushort *)(puVar8 + 2) = (ushort)bStack_77;
    if (bVar2 == 0) {
      puVar8[5] = puVar15[0xc];
      memcpy(puVar8 + 6,puVar15 + 0xd,6);
    }
    else {
      memcpy(puVar8 + 6,param_1 + 0x15,6);
      puVar8[5] = param_1[0x37];
      if ((puVar15[0xb] & 2) == 0) {
        memset(puVar8 + 0xc,0,6);
      }
      else {
        memcpy(puVar8 + 0xc,param_1 + 9,6);
      }
      if ((param_1[0x37] & 2) == 0) {
        memset(puVar8 + 0x12,0,6);
      }
      else {
        memcpy(puVar8 + 0x12,param_1 + 0xf,6);
      }
      *(undefined2 *)(puVar8 + 0x18) = *(undefined2 *)(param_1 + 0x1e);
      *(undefined2 *)(puVar8 + 0x1a) = *(undefined2 *)(param_1 + 0x20);
      *(undefined2 *)(puVar8 + 0x1c) = *(undefined2 *)(param_1 + 0x22);
      puVar8[0x1e] = param_1[0x2a];
    }
  }
  (**(code **)(_r_ip_funcs_p + 0x8c))(puVar8,*(code **)(_r_ip_funcs_p + 0x8c));
  if (param_1[0x35] != 0) {
    puVar8 = (undefined1 *)
             (**(code **)(_r_modules_funcs_p + 200))
                       (0x1104,0,0x3e,6,*(code **)(_r_modules_funcs_p + 200));
    *puVar8 = 0x14;
    iVar10 = _r_ip_funcs_p;
    *(ushort *)(puVar8 + 2) = (ushort)bStack_77;
    puVar8[4] = param_1[0x36];
    (**(code **)(iVar10 + 0x8c))(*(code **)(iVar10 + 0x8c));
  }
_L696:
  if ((*(char *)(_p_llm_env + 0xd7) == '\x02') && ((bVar18 != 0 || (param_1[1] != 0)))) {
    puVar8 = (undefined1 *)
             (**(code **)(_r_modules_funcs_p + 200))
                       (0x1104,0,0x3e,8,*(code **)(_r_modules_funcs_p + 200));
    *puVar8 = 0x12;
    puVar8[1] = param_1[1];
    puVar8[2] = *puVar15;
    iVar10 = _r_ip_funcs_p;
    *(ushort *)(puVar8 + 4) = (ushort)bStack_77;
    puVar8[6] = param_1[0x38];
    (**(code **)(iVar10 + 0x8c))(*(code **)(iVar10 + 0x8c));
  }
  iVar16 = iVar16 + *(int *)(_p_llm_env + 8);
  if (*(char *)(iVar16 + 0x40) != '\x02') {
    *(undefined1 *)(iVar16 + 0x3e) = 0xff;
  }
  return 0;
}

