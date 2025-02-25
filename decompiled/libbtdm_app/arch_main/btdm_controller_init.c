/*
 * Last changed at upstream commit 2ce747aec8008d008fe34fa375a2aea3e7e48e9a
 * https://github.com/espressif/esp32c3-bt-lib/commit/2ce747aec8008d008fe34fa375a2aea3e7e48e9a
 * Upstream date: 2025-02-25 15:16:47 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(723439d)
 * Source: libbtdm_app -> arch_main.o -> btdm_controller_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 btdm_controller_init(int *param_1)

{
  byte bVar1;
  byte bVar2;
  undefined1 uVar3;
  ushort uVar4;
  undefined2 uVar5;
  bool bVar6;
  void *pvVar7;
  int *piVar8;
  int *piVar9;
  char cVar10;
  char *pcVar11;
  int iVar12;
  int iVar13;
  undefined4 uVar14;
  code *pcVar15;
  uint uVar16;
  undefined1 uStack_34;
  byte bStack_33;
  
  uVar14 = 0xffffffff;
  if (_g_rw_init_sem != 0) goto _L336;
  _r_plf_funcs_p =
       (void *)(**(code **)(_r_osi_funcs_p + 0x78))(0x118,*(code **)(_r_osi_funcs_p + 0x78));
  if (((_r_plf_funcs_p == (void *)0x0) ||
      (_r_modules_funcs_p =
            (void *)(**(code **)(_r_osi_funcs_p + 0x78))(0x3d0,*(code **)(_r_osi_funcs_p + 0x78)),
      _r_modules_funcs_p == (void *)0x0)) ||
     (_r_ip_funcs_p =
           (void *)(**(code **)(_r_osi_funcs_p + 0x78))(0x9e4,*(code **)(_r_osi_funcs_p + 0x78)),
     _r_ip_funcs_p == (void *)0x0)) {
    if (0 < _g_bt_plf_log_level) {
      ets_printf("Funcs table create fails\n");
    }
    btdm_funcs_table_destroy();
    uVar14 = 0xfffffffe;
    goto _L336;
  }
  memcpy(_r_plf_funcs_p,&r_plf_funcs_ro,0x118);
  memcpy(_r_modules_funcs_p,&r_modules_funcs_ro,0x3d0);
  memcpy(_r_ip_funcs_p,&r_ip_funcs_ro,0x9e4);
  (**(code **)(_r_osi_funcs_p + 0xe4))(*(code **)(_r_osi_funcs_p + 0xe4));
  if ((*param_1 == 0x5a5aa5a5) && (param_1[1] == 0x2502230)) {
    if (((((uint)param_1[0xb] >> 0x10) - 1 & 0xff) < 2) &&
       ((((uint)param_1[0xb] >> 0x18) - 1 & 0xff) < 2)) {
      if (*(byte *)(param_1 + 0xc) < 2) {
        *(undefined1 *)(param_1 + 0xc) = 2;
      }
      if (*(ushort *)(param_1 + 0xd) < 0x101) {
        if (*(byte *)((int)param_1 + 0x1e) < 0x10) {
          (**(code **)((int)_r_plf_funcs_p + 0x44))(param_1,*(code **)((int)_r_plf_funcs_p + 0x44));
          sdk_config_set_mask(param_1[8]);
          sdk_config_set_opts_ext(param_1 + 8);
          sdk_config_overwrite_priv_opts();
          sdk_config_set_derived_opts();
          iVar12 = (**(code **)((int)_r_plf_funcs_p + 0xf0))(*(code **)((int)_r_plf_funcs_p + 0xf0))
          ;
          if (*(char *)(iVar12 + 0x1e) != '\0') {
            uVar14 = 0xfffffff5;
            if (0 < _g_bt_plf_log_level) {
              ets_printf("Controller lib error, need flash lib\n");
              uVar14 = 0xfffffff5;
            }
            goto _L336;
          }
          if ((*(char *)((int)param_1 + 0x17) == '\0') &&
             (iVar12 = (**(code **)((int)_r_plf_funcs_p + 0xe8))
                                 (param_1[6],*(code **)((int)_r_plf_funcs_p + 0xe8)), iVar12 != 0))
          goto _L451;
          iVar12 = (**(code **)((int)_r_plf_funcs_p + 0x38))(*(code **)((int)_r_plf_funcs_p + 0x38))
          ;
          uStack_34 = *(undefined1 *)(iVar12 + 0xd);
          bStack_33 = DAT_0001302f;
          (**(code **)((int)_r_plf_funcs_p + 0x24))
                    (&uStack_34,*(code **)((int)_r_plf_funcs_p + 0x24));
          if (DAT_0001302e == '\0') {
            btdm_hli_get_null_funcs();
          }
          else {
            btdm_hli_get_funcs();
          }
          btdm_hli_funcs_register();
          _btdm_env_p = (int *)(**(code **)(_r_osi_funcs_p + 0x74))
                                         (0x28,*(code **)(_r_osi_funcs_p + 0x74));
          if (_btdm_env_p != (int *)0x0) {
            memset(_btdm_env_p,0,0x28);
            iVar12 = (**(code **)((int)_r_ip_funcs_p + 0x244))
                               (*(code **)((int)_r_ip_funcs_p + 0x244));
            iVar13 = (**(code **)((int)_r_ip_funcs_p + 0x4d0))
                               (*(code **)((int)_r_ip_funcs_p + 0x4d0));
            if (iVar13 == 0) {
              iVar12 = 0;
            }
            iVar13 = (**(code **)((int)_r_ip_funcs_p + 0xe4))(*(code **)((int)_r_ip_funcs_p + 0xe4))
            ;
            bVar6 = iVar13 != 0 && iVar12 != 0;
            if ((DAT_0001302d != '\0') &&
               (iVar12 = (**(code **)((int)_r_plf_funcs_p + 0x4c))
                                   (*(code **)((int)_r_plf_funcs_p + 0x4c)), iVar12 == 0)) {
              bVar6 = false;
            }
            iVar12 = (**(code **)((int)_r_ip_funcs_p + 0x44))(*(code **)((int)_r_ip_funcs_p + 0x44))
            ;
            if ((iVar12 != 0) && (bVar6)) {
              iVar12 = (**(code **)((int)_r_plf_funcs_p + 0x38))
                                 (*(code **)((int)_r_plf_funcs_p + 0x38));
              bVar1 = *(byte *)(iVar12 + 0xd);
              iVar12 = (**(code **)((int)_r_plf_funcs_p + 0x38))
                                 (*(code **)((int)_r_plf_funcs_p + 0x38));
              bVar2 = *(byte *)(iVar12 + 0xd);
              uVar16 = (uint)DAT_0001302f;
              iVar12 = (**(code **)((int)_r_plf_funcs_p + 0x38))
                                 (*(code **)((int)_r_plf_funcs_p + 0x38));
              piVar8 = _btdm_env_p;
              iVar13 = 0;
              if (DAT_0001302e != '\0') {
                iVar13 = uVar16 * 0xe0 + (uint)*(byte *)(iVar12 + 0xd) * 0x88;
              }
              pcVar15 = *(code **)(_r_osi_funcs_p + 0x78);
              _btdm_env_p[1] =
                   ((bVar2 + 2) * 0xc + (uint)bVar1 * 0xe6 + 0x25b + iVar13 & 0xfffffffc) + 0xc;
              iVar12 = (*pcVar15)(pcVar15);
              pvVar7 = _r_plf_funcs_p;
              *piVar8 = iVar12;
              iVar12 = (**(code **)((int)pvVar7 + 0x38))(*(code **)((int)pvVar7 + 0x38));
              piVar8 = _btdm_env_p;
              uVar16 = 0;
              if (DAT_0001302e != '\0') {
                uVar16 = (uint)DAT_0001302f * 400;
                if ((uint)DAT_0001302f * 400 < 0x1800) {
                  uVar16 = 0x1800;
                }
              }
              pcVar15 = *(code **)(_r_osi_funcs_p + 0x78);
              _btdm_env_p[3] =
                   (((uint)*(byte *)(iVar12 + 0xd) * 0x104 + 0x8ef) * 2 + 0x675 + uVar16 &
                   0xfffffffc) + 0xc;
              iVar12 = (*pcVar15)(pcVar15);
              pvVar7 = _r_plf_funcs_p;
              piVar8[2] = iVar12;
              iVar12 = (**(code **)((int)pvVar7 + 0xf0))(*(code **)((int)pvVar7 + 0xf0));
              uVar4 = *(ushort *)(iVar12 + 8);
              iVar12 = (**(code **)((int)_r_plf_funcs_p + 0xf0))
                                 (*(code **)((int)_r_plf_funcs_p + 0xf0));
              piVar8 = _btdm_env_p;
              pcVar15 = *(code **)(_r_osi_funcs_p + 0x78);
              _btdm_env_p[5] = (uint)*(ushort *)(iVar12 + 6) * 0xc + (uint)uVar4 * 0x10 + 0x29c;
              iVar12 = (*pcVar15)(pcVar15);
              cVar10 = DAT_0001302e;
              piVar8[4] = iVar12;
              piVar8 = _btdm_env_p;
              iVar12 = 1;
              if (cVar10 != '\0') {
                iVar12 = 0xc00;
              }
              pcVar15 = *(code **)(_r_osi_funcs_p + 0x78);
              _btdm_env_p[7] = (iVar12 + 3U & 0xfffffffc) + 0xc;
              iVar12 = (*pcVar15)(pcVar15);
              piVar9 = _btdm_env_p;
              piVar8[6] = iVar12;
              if ((((*piVar9 != 0) && (piVar9[2] != 0)) && (piVar9[4] != 0)) &&
                 ((piVar9[7] == 0 || (piVar9[6] != 0)))) {
                if (2 < _g_bt_plf_log_level) {
                  ets_printf("RWIP Heap alloc: ENV [%p %d], MSG [%p %d], NORET [%p %d], DB [%p %d]\n"
                             ,piVar9[1],piVar9[3],piVar9[5],piVar9[6]);
                }
                iVar12 = (**(code **)((int)_r_plf_funcs_p + 0x38))
                                   (*(code **)((int)_r_plf_funcs_p + 0x38));
                if ((*(char *)(iVar12 + 0x17) != '\0') &&
                   (iVar12 = (**(code **)((int)_r_plf_funcs_p + 0x38))
                                       (*(code **)((int)_r_plf_funcs_p + 0x38)),
                   piVar8 = _btdm_env_p, *(char *)(iVar12 + 0x17) == '\x01')) {
                  iVar12 = (**(code **)(_r_osi_funcs_p + 0x78))
                                     (0xc,*(code **)(_r_osi_funcs_p + 0x78));
                  piVar9 = _btdm_env_p;
                  piVar8[9] = iVar12;
                  if ((void *)piVar9[9] == (void *)0x0) goto _L355;
                  memset((void *)piVar9[9],0,0xc);
                }
                if (2 < _g_bt_plf_log_level) {
                  ets_printf("Uart ENV [%p], VHCI ENV [%p]\n",_btdm_env_p[8],_btdm_env_p[9]);
                }
                _g_rw_init_sem =
                     (**(code **)(_r_osi_funcs_p + 0x24))(1,0,*(code **)(_r_osi_funcs_p + 0x24));
                if (_g_rw_init_sem == 0) {
                  uVar14 = 0xfffffffb;
                }
                else {
                  _g_rw_schd_queue =
                       (**(code **)(_r_osi_funcs_p + 0x4c))(5,8,*(code **)(_r_osi_funcs_p + 0x4c));
                  if (_g_rw_schd_queue == 0) {
                    uVar14 = 0xfffffffa;
                  }
                  else {
                    pcVar15 = *(code **)(_r_osi_funcs_p + 0x24);
                    iVar12 = (**(code **)((int)_r_plf_funcs_p + 0xf8))
                                       (*(code **)((int)_r_plf_funcs_p + 0xf8));
                    uVar14 = (*pcVar15)(1,0);
                    pvVar7 = _r_plf_funcs_p;
                    *(undefined4 *)(iVar12 + 8) = uVar14;
                    iVar12 = (**(code **)((int)pvVar7 + 0xf8))(*(code **)((int)pvVar7 + 0xf8));
                    if (*(int *)(iVar12 + 8) == 0) {
                      uVar14 = 0xfffffff9;
                    }
                    else {
                      _g_waking_sleeping_sem =
                           (**(code **)(_r_osi_funcs_p + 0x24))
                                     (1,1,*(code **)(_r_osi_funcs_p + 0x24));
                      if (_g_waking_sleeping_sem == 0) {
                        return 0xfffffff8;
                      }
                      pcVar15 = *(code **)(_r_osi_funcs_p + 100);
                      iVar12 = (**(code **)((int)_r_plf_funcs_p + 0x38))
                                         (*(code **)((int)_r_plf_funcs_p + 0x38));
                      uVar5 = *(undefined2 *)(iVar12 + 8);
                      iVar12 = (**(code **)((int)_r_plf_funcs_p + 0x38))
                                         (*(code **)((int)_r_plf_funcs_p + 0x38));
                      uVar3 = *(undefined1 *)(iVar12 + 10);
                      iVar12 = (**(code **)((int)_r_plf_funcs_p + 0x38))
                                         (*(code **)((int)_r_plf_funcs_p + 0x38));
                      iVar12 = (*pcVar15)(btdm_controller_task,"btController",uVar5,0,uVar3,
                                          &g_rw_controller_task_handle,*(undefined1 *)(iVar12 + 0xb)
                                         );
                      if (iVar12 == 1) {
                        (**(code **)((int)_r_plf_funcs_p + 0x28))
                                  (7,0,0,1,*(code **)((int)_r_plf_funcs_p + 0x28));
                        (**(code **)(_r_osi_funcs_p + 0x34))
                                  (_g_rw_init_sem,10000,*(code **)(_r_osi_funcs_p + 0x34));
                        return 0;
                      }
                      uVar14 = 0xfffffff7;
                    }
                  }
                }
                goto _L336;
              }
            }
          }
_L355:
          (**(code **)((int)_r_ip_funcs_p + 0x240))(*(code **)((int)_r_ip_funcs_p + 0x240));
          (**(code **)((int)_r_ip_funcs_p + 0x4cc))(*(code **)((int)_r_ip_funcs_p + 0x4cc));
          (**(code **)((int)_r_ip_funcs_p + 0xe0))(*(code **)((int)_r_ip_funcs_p + 0xe0));
          if (DAT_0001302d != '\0') {
            (**(code **)((int)_r_plf_funcs_p + 0x48))(*(code **)((int)_r_plf_funcs_p + 0x48));
          }
          (**(code **)((int)_r_ip_funcs_p + 0x40))(*(code **)((int)_r_ip_funcs_p + 0x40));
          if (*_btdm_env_p != 0) {
            (**(code **)(_r_osi_funcs_p + 0x7c))(*(code **)(_r_osi_funcs_p + 0x7c));
          }
          if (_btdm_env_p[2] != 0) {
            (**(code **)(_r_osi_funcs_p + 0x7c))(*(code **)(_r_osi_funcs_p + 0x7c));
          }
          if (_btdm_env_p[4] != 0) {
            (**(code **)(_r_osi_funcs_p + 0x7c))(*(code **)(_r_osi_funcs_p + 0x7c));
          }
          if (_btdm_env_p[6] != 0) {
            (**(code **)(_r_osi_funcs_p + 0x7c))(*(code **)(_r_osi_funcs_p + 0x7c));
          }
          if (_btdm_env_p[9] != 0) {
            (**(code **)(_r_osi_funcs_p + 0x7c))(*(code **)(_r_osi_funcs_p + 0x7c));
            _btdm_env_p[9] = 0;
          }
          uVar14 = 0xfffffffc;
          if (_btdm_env_p != (int *)0x0) {
            (**(code **)(_r_osi_funcs_p + 0x7c))(*(code **)(_r_osi_funcs_p + 0x7c));
            _btdm_env_p = (int *)0x0;
          }
          goto _L336;
        }
        if (0 < _g_bt_plf_log_level) {
          pcVar11 = "Default Tx Power Invalid: 0x%x\n";
          goto _L452;
        }
      }
      else if (0 < _g_bt_plf_log_level) {
        pcVar11 = "Invalid scan backoff upperlimitmax: 0x%x\n";
        goto _L452;
      }
    }
    else if (0 < _g_bt_plf_log_level) {
      pcVar11 = "Hardware Target Code Invalid: 0x%x\n";
_L452:
      ets_printf(pcVar11);
    }
  }
  else if (0 < _g_bt_plf_log_level) {
    ets_printf("Config struct mismatch: magic=%08x, ver=%08x\n",0x5a5aa5a5,0x2502230);
  }
_L451:
  uVar14 = 0xfffffffd;
_L336:
  btdm_controller_deinit_internal();
  return uVar14;
}

